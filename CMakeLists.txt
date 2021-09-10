# version 3.11 or later of CMake needed later for installing GoogleTest
# so let's require it now.
cmake_minimum_required(VERSION 3.11-3.18)

project(
    gen_algo
    VERSION 0.1
    DESCRIPTION "A genetic algorithm designed to find analytical solutions to data")

add_subdirectory(lib)   # look in animal subdirectory for CMakeLists.txt to process
add_subdirectory(apps)    # look in apps subdirectory for CMakeLists.txt to process