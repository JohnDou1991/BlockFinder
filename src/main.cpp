#include <iostream>
#include <memory>

#include "BlockFinder.hpp"
#include "TestCases.hpp"

int main( int argc, char** argv )
{
    std::unique_ptr<IBlockFinder> finder = std::make_unique<BlockFinder>();

    auto test = [&finder]( const auto& testcase ) {
        int solution = finder->Find( testcase.blocks, testcase.req );
        if ( testcase.expected == solution )
            std::cout << testcase.name << ": ok" << std::endl;
        else
            std::cerr << testcase.name << ": nok - expected: " 
                      << testcase.expected << " got: " << solution << std::endl;
    };
    test( testcase::original );
    test( testcase::empty_req );
    test( testcase::empty_blocks );
    test( testcase::too_many_reqs );
    test( testcase::too_many_reqs2 );
    test( testcase::all_true );
    test( testcase::all_false );
    test( testcase::only_one_block );
    test( testcase::only_one_req_one_block );
    test( testcase::only_one_req_n_blocks );
    test( testcase::only_one_req_per_block );
    return 0;
}