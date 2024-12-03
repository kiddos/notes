cmake_minimum_required(VERSION 3.14)
project(leveldb-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
    leveldb
    GIT_REPOSITORY https://github.com/google/leveldb
    GIT_TAG        main
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(leveldb)

include_directories(${leveldb_SOURCE_DIR}/include)

add_executable(sample sample.cc)
target_link_libraries(sample PRIVATE leveldb)
