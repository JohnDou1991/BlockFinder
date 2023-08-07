cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(BlockFinderTest C CXX)

set( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/ )

include_directories( "${SRC_DIR}" )

add_executable( BlockFinderTest ${SRC_DIR}/main.cpp ${SRC_DIR}/BlockFinder.cpp )