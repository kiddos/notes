cmake_minimum_required(VERSION 3.14)
project(benchmark-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

enable_testing()

set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
    GIT_SHALLOW    TRUE
)
FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG        v1.9.1
    GIT_SHALLOW    TRUE
)
FetchContent_Declare(
    oneTBB
    GIT_REPOSITORY https://github.com/uxlfoundation/oneTBB
    GIT_TAG        v2022.0.0
    GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(googletest benchmark oneTBB)

add_library(lib lib.cc)
target_link_libraries(lib TBB::tbb)

add_executable(benchmark_sample sample.cc)
target_link_libraries(benchmark_sample GTest::gtest_main benchmark::benchmark lib)
