cmake_minimum_required(VERSION 3.16)
project(rocksdb-example C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(WITH_GFLAGS OFF CACHE BOOL "" FORCE)
set(WITH_TESTS OFF CACHE BOOL "" FORCE)
set(WITH_TOOLS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
  rocksdb
  GIT_REPOSITORY https://github.com/facebook/rocksdb
  GIT_TAG        v11.8.1
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(rocksdb)

add_executable(example example.cc)
target_compile_options(example INTERFACE -Wall -Wextra)
target_link_libraries(example PRIVATE rocksdb)
