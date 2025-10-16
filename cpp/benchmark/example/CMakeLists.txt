cmake_minimum_required(VERSION 3.16)
project(benchmark-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(TBB_TEST OFF CACHE BOOL "Disable TBB tests" FORCE)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Disable benchmark tests" FORCE)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.17.0
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG        v1.9.4
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_Declare(
  oneTBB
  GIT_REPOSITORY https://github.com/uxlfoundation/oneTBB
  GIT_TAG        v2022.0.0
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(googletest benchmark oneTBB)

enable_testing()

add_library(lib lib.cc)
target_link_libraries(lib PRIVATE TBB::tbb)

add_executable(benchmark_example example.cc)
target_link_libraries(benchmark_example PRIVATE
  GTest::gtest_main
  benchmark::benchmark
  lib)
