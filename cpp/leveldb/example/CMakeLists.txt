cmake_minimum_required(VERSION 3.16)
project(leveldb-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-parameter")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(LEVELDB_BUILD_TESTS OFF CACHE BOOL "Disable leveldb tests" FORCE)
set(LEVELDB_BUILD_BENCHMARKS OFF CACHE BOOL "Disable leveldb benchmark" FORCE)
set(LEVELDB_INSTALL OFF CACHE BOOL "Disable leveldb install" FORCE)
FetchContent_Declare(
  leveldb
  GIT_REPOSITORY https://github.com/google/leveldb
  GIT_TAG        1.23
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(leveldb)

add_executable(example example.cc)
target_include_directories(example PRIVATE ${leveldb_SOURCE_DIR}/include)
target_link_libraries(example PRIVATE leveldb)
