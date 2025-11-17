cmake_minimum_required(VERSION 3.16)
project(g2o-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(G2O_BUILD_APPLICATIONS OFF CACHE BOOL "Disable building G2O's example applications.")
set(G2O_BUILD_EXAMPLES OFF CACHE BOOL "Disable building G2O's examples.")
set(G2O_BUILD_TESTS OFF CACHE BOOL "Disable building G2O's tests.")
set(G2O_USE_OPENMP OFF CACHE BOOL "Disable OpenMP support.")
FetchContent_Declare(
  g2o
  GIT_REPOSITORY https://github.com/RainerKuemmerle/g2o.git
  GIT_TAG        master 
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(g2o)

add_executable(example example.cc)
target_include_directories(example PRIVATE 
  ${g2o_SOURCE_DIR}
  ${g2o_BINARY_DIR}
)
target_link_libraries(example
  PRIVATE
  g2o::core
  g2o::stuff
)
