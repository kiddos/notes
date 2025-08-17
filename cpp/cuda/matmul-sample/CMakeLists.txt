cmake_minimum_required(VERSION 3.14)
project(cuda-matmul-sample LANGUAGES C CXX CUDA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  Eigen
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
  GIT_TAG 3.4.0
  GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(Eigen)

include_directories(${Eigen_SOURCE_DIR})

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

add_executable(sample sample.cc sample_matmul.cu)
target_link_libraries(sample PUBLIC Eigen3::Eigen ${CUDA_LIBRARIES})
target_include_directories(sample PUBLIC ${CUDA_INCLUDE_DIRS})
