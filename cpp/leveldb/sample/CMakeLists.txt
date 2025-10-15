cmake_minimum_required(VERSION 3.16)
project(leveldb-sample CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-parameter")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(LEVELDB_BUILD_TESTS OFF)
set(LEVELDB_BUILD_BENCHMARKS OFF)
set(LEVELDB_INSTALL OFF)
FetchContent_Declare(
  leveldb
  GIT_REPOSITORY https://github.com/google/leveldb
  GIT_TAG        1.23
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(leveldb)

add_executable(sample sample.cc)
target_include_directories(sample PRIVATE ${leveldb_SOURCE_DIR}/include)
target_link_libraries(sample PRIVATE leveldb)
