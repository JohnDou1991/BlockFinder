#pragma once

#include "IBlockFinder.hpp"

class FastBlockSearcher final
{
    using BlocksIndexes = std::vector<int>;
    std::unordered_map<BuildingType, BlocksIndexes> m_processedData;

public:
    /// time complexity: n*m
    /// space complexity: n*m
    explicit FastBlockSearcher( const Blocks& );

    /// time complexity: log n 
    int FindClosest( const BuildingType&, const int index );

    /// time complexity: constant
    bool HasType( const BuildingType& ) const;
};

class BlockFinder final : public IBlockFinder
{
public:
    /// time complexity: n*m + m + n*m*log n
    /// space complexity: n*m
    int Find( const Blocks&, const Req& ) override;
    ~BlockFinder() = default;
};