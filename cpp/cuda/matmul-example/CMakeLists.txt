cmake_minimum_required(VERSION 3.16)
project(matmul-example C CXX CUDA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  Eigen
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
  GIT_TAG        3.4.0
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(Eigen)

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Disable benchmark tests" FORCE)
FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG        v1.9.4
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(benchmark)

find_package(CUDA REQUIRED)

if (NOT CUDA_FOUND)
  message(FATAL_ERROR "CUDA was not found. Please ensure it's installed and accessible via your PATH or CUDA_PATH environment variable.")
else()
  message(STATUS "Found CUDA toolkit version ${CUDA_VERSION}")
  message(STATUS "CUDA NVCC executable: ${CUDA_NVCC_EXECUTABLE}")
  message(STATUS "CUDA Libraries: ${CUDA_LIBRARIES}")
  message(STATUS "CUDA Include Directories: ${CUDA_INCLUDE_DIRS}")
  message(STATUS "CUDA CXX Compiler: ${CUDA_HOST_COMPILER}")
endif()

set(CUDA_PROPAGATE_HOST_FLAGS OFF)
set(CUDA_SEPARABLE_COMPILATION ON)

include_directories()

add_executable(example example.cc matmul_example.cu)
target_include_directories(example PRIVATE
  ${Eigen_SOURCE_DIR}
  ${CUDA_INCLUDE_DIRS})
target_link_libraries(example PRIVATE
  Eigen3::Eigen
  ${CUDA_LIBRARIES}
  benchmark::benchmark
)
