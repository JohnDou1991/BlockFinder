#include "BlockFinder.hpp"

FastBlockSearcher::FastBlockSearcher( const Blocks& blocks )
{
    m_processedData.reserve(blocks.size());
    for ( size_t i = 0; i < blocks.size(); ++i )
        for ( const auto&[type,exists] : blocks[i].buildings )
            if ( exists )
                m_processedData[type].push_back(i);
}

int FastBlockSearcher::FindClosest( const BuildingType& type, const int index )
{
    auto it = m_processedData.find(type);
    if ( it == m_processedData.end() )
        return -1; // error

    const auto& indexes = it->second;

	auto lb = std::lower_bound( indexes.begin(), indexes.end(), index );

    if ( lb == indexes.end() )
        return std::abs( indexes.back() - index );
    else if ( lb == indexes.begin() )
        return std::abs( indexes.front() - index );
    else
    {
        auto previous = std::prev(lb);
        return std::min( std::abs( index - *previous ), std::abs( *lb - index ) );
    }
}

bool FastBlockSearcher::HasType( const BuildingType& type ) const
{
    return m_processedData.find(type) != m_processedData.end();
}

int BlockFinder::Find( const Blocks& blocks, const Req& req )
{
    if ( req.empty() || blocks.empty() )
        return -1; // no solution

    FastBlockSearcher searcher(blocks);

    // check if task has solution
    for ( const auto& type : req )
        if ( !searcher.HasType(type) )
            return -1; // no solution

    // find solution
    int solution = -1;
    int minimal_farthest = std::numeric_limits<int>::max();
    for ( size_t i = 0; i < blocks.size(); ++i )
    {
        int farthest = -1;
        for ( const auto& type : req )
        {
            farthest = std::max( farthest, searcher.FindClosest( type, i ) );
            if ( farthest > minimal_farthest ) // no need to check further, already have better solution
                break;
        }

        if ( farthest >= 0 && minimal_farthest > farthest )
        {
            minimal_farthest = farthest;
            solution = i;
            if ( minimal_farthest == 0 ) // best possible solution
                return solution;
        }
    }

	return solution;
}