#include "IBlockFinder.hpp"

namespace testcase
{
    struct {
        const Blocks blocks = 
        {
            Block({
                { "gym", false },
                { "school", true },
                { "store", false }
            }),
            Block({
                { "gym", true },
                { "school", false },
                { "store", false }
            }),
            Block({
                { "gym", true },
                { "school", true },
                { "store", false }
            }),
            Block({
                { "gym", false },
                { "school", true },
                { "store", false }
            }),
            Block({
                { "gym", false },
                { "school", true },
                { "store", true }
            }),
        };

        const Req req = { "gym", "school", "store" };
        const int expected = 3;
        const std::string name = "original";
    } original;

    struct {
        const Blocks blocks = 
        {
            Block({
                { "gym", false },
                { "school", true },
                { "store", false }
            }),
        };
        const Req req = {};
        const int expected = -1;
        const std::string name = "empty_req";
    } empty_req;

    struct {
        const Blocks blocks = { };
        const Req req = { "gym", "school", "store" };
        const int expected = -1;
        const std::string name = "empty_blocks";
    } empty_blocks;

    struct {
        const Blocks blocks = 
        {
            Block({
                { "gym", false },
                { "school", true },
                { "store", false }
            }),
            Block({
                { "gym", true },
                { "school", false },
                { "store", false }
            }),
            Block({
                { "gym", true },
                { "school", true },
                { "store", false }
            }),
            Block({
                { "gym", false },
                { "school", true },
                { "store", false }
            }),
            Block({
                { "gym", false },
                { "school", true },
                { "store", true }
            }),
        };
        const Req req = { "gym", "school", "store", "cinema" };
        const int expected = -1;
        const std::string name = "too_many_reqs";
    } too_many_reqs;

    struct {
        const Blocks blocks = 
        {
            Block({
                { "gym", false },
                { "school", true },
                { "store", false }
            }),
            Block({
                { "gym", true },
                { "school", false },
                { "store", false },
                { "cinema", true }
            }),
            Block({
                { "gym", true },
                { "school", true },
                { "store", false }
            }),
            Block({
                { "gym", false },
                { "school", true },
                { "store", false }
            }),
            Block({
                { "gym", false },
                { "school", true },
                { "store", true }
            }),
        };
        const Req req = { "gym", "school", "store", "cinema" };
        const int expected = 2;
        const std::string name = "too_many_reqs2";
    } too_many_reqs2;

    struct {
        const Blocks blocks = 
        {
            Block({
                { "gym", true },
                { "school", true },
                { "store", true }
            }),
            Block({
                { "gym", true },
                { "school", true },
                { "store", true }
            }),
            Block({
                { "gym", true },
                { "school", true },
                { "store", true }
            }),
            Block({
                { "gym", true },
                { "school", true },
                { "store", true }
            }),
            Block({
                { "gym", true },
                { "school", true },
                { "store", true }
            }),
        };

        const Req req = { "gym", "school", "store" };
        const int expected = 0;
        const std::string name = "all_true";
    } all_true;

    struct {
        const Blocks blocks = 
        {
            Block({
                { "gym", false },
                { "school", false },
                { "store", false }
            }),
            Block({
                { "gym", false },
                { "school", false },
                { "store", false }
            }),
            Block({
                { "gym", false },
                { "school", false },
                { "store", false }
            }),
            Block({
                { "gym", false },
                { "school", false },
                { "store", false }
            }),
            Block({
                { "gym", false },
                { "school", false },
                { "store", false }
            }),
        };

        const Req req = { "gym", "school", "store" };
        const int expected = -1;
        const std::string name = "all_false";
    } all_false;

    struct{
        const Blocks blocks = 
        {
            Block({
                { "gym", true },
                { "school", true },
                { "store", true }
            }),
        };

        const Req req = { "gym", "school", "store" };
        const int expected = 0;
        const std::string name = "only_one_block";
    } only_one_block;

    struct{
        const Blocks blocks = 
        {
            Block({
                { "gym", true },
                { "school", true },
                { "store", true }
            }),
        };

        const Req req = { "school" };
        const int expected = 0;
        const std::string name = "only_one_req_one_block";
    } only_one_req_one_block;

    struct{
        const Blocks blocks = 
        {
            Block({
                { "gym", true },
                { "school", false },
                { "store", false }
            }),
            Block({
                { "gym", false },
                { "school", false },
                { "store", true }
            }),
            Block({
                { "gym", false },
                { "school", true },
                { "store", false }
            }),
        };

        const Req req = { "school" };
        const int expected = 2;
        const std::string name = "only_one_req_n_blocks";
    } only_one_req_n_blocks;

    struct{
        const Blocks blocks = 
        {
            Block({
                { "gym", true }
            }),
            Block({
                { "school", true }
            }),
            Block({
                { "store", true }
            }),
        };

        const Req req = { "gym", "school", "store" };
        const int expected = 1;
        const std::string name = "only_one_req_per_block";
    } only_one_req_per_block;
}