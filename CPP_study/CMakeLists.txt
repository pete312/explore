
cmake_minimum_required(VERSION 2.8)


project(LEARN)


find_package(Boost)

set(CMAKE_CXX_FLAGS "-g ")
#set(CMAKE_CXX_FLAGS "-g -Wall")


add_subdirectory(time)
add_subdirectory(iterators)
add_subdirectory(containers)
add_subdirectory(types)
add_subdirectory(boost)
#add_subdirectory(thread)
add_subdirectory(patterns)
add_subdirectory(parsing)
#add_subdirectory(benchmarks)



