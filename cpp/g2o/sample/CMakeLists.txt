cmake_minimum_required(VERSION 3.14)
project(g2o-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
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
  # GIT_SUBMODULES OFF 
  GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(g2o)

include_directories(${g2o_SOURCE_DIR})

add_executable(sample sample.cc)

target_link_libraries(sample
  PRIVATE
  g2o::core
  g2o::stuff
  # g2o::types_slam2d
  # g2o::solver_pcg
  # g2o_core
  # g2o_stuff
  # g2o_types_slam2d
  # g2o_solver_cholmod
  # g2o_solver_pcg
)

target_include_directories(sample
  PRIVATE ${g2o_BINARY_DIR}
)
