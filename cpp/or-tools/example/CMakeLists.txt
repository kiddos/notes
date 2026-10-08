cmake_minimum_required(VERSION 3.16)
project(or-tools-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(BUILD_DEPS ON CACHE BOOL "Build dependencies" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "Build dependencies" FORCE)
FetchContent_Declare(
  ortools
  GIT_REPOSITORY https://github.com/google/or-tools
  GIT_TAG        stable
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(ortools)

add_executable(example_nurse_scheduling example_nurse_scheduling.cc)
target_compile_options(example_nurse_scheduling INTERFACE -Wall -Wextra)
target_link_libraries(example_nurse_scheduling PRIVATE ortools)

add_executable(example_job_shop example_job_shop.cc)
target_compile_options(example_job_shop INTERFACE -Wall -Wextra)
target_link_libraries(example_job_shop PRIVATE ortools)
