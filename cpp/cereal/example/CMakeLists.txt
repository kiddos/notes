cmake_minimum_required(VERSION 3.16)
project(cereal-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(BUILD_DOC OFF CACHE BOOL "Disable cereal doc" FORCE)
set(BUILD_SANDBOX OFF CACHE BOOL "Disable cereal sandbox" FORCE)
set(SKIP_PERFORMANCE_COMPARISON ON CACHE BOOL "Disable cereal performance comparison" FORCE)
FetchContent_Declare(
  cereal
  GIT_REPOSITORY https://github.com/USCiLab/cereal.git
  GIT_TAG        v1.3.2
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(cereal)

add_executable(example example.cc)
target_include_directories(example PRIVATE
  ${cereal_SOURCE_DIR}/include
)
