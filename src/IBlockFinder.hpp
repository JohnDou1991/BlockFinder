#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using BuildingType = std::string;

struct Block
{
    Block( const std::unordered_map<BuildingType, bool>& buildings ) : buildings(buildings)
    { }
    const std::unordered_map<BuildingType, bool> buildings;
};

using Blocks = std::vector<Block>;
using Req = std::unordered_set<BuildingType>;

class IBlockFinder
{
public:
    virtual int Find( const Blocks&, const Req& ) = 0;
    virtual ~IBlockFinder() = default;
};