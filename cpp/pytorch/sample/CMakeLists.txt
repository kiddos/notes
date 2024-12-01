cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(pytorch-sample-app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pthread")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

include(FetchContent)

set(TORCH_VERSION "2.5.1") # Update this as needed

set(FETCHCONTENT_QUIET FALSE)
# Fetch PyTorch
FetchContent_Declare(
    libtorch
    URL https://download.pytorch.org/libtorch/cu121/libtorch-cxx11-abi-shared-with-deps-${TORCH_VERSION}%2Bcu121.zip
)

FetchContent_MakeAvailable(libtorch)
set(CMAKE_PREFIX_PATH "${libtorch_SOURCE_DIR}/share/cmake/Torch" ${CMAKE_PREFIX_PATH})
find_package(Torch REQUIRED)

# stb
FetchContent_Declare(
    stb
    GIT_REPOSITORY https://github.com/nothings/stb
    GIT_TAG master
)
FetchContent_MakeAvailable(stb)
include_directories(${stb_SOURCE_DIR})

add_executable(sample sample.cc)
target_link_libraries(sample PRIVATE "${TORCH_LIBRARIES}")

add_executable(sample_eval sample_eval.cc)
target_link_libraries(sample_eval PRIVATE "${TORCH_LIBRARIES}")

add_executable(sample_resnet sample_resnet.cc)
target_compile_options(sample_resnet PRIVATE -DSTB_IMAGE_IMPLEMENTATION -DSTB_IMAGE_RESIZE_IMPLEMENTATION)
target_link_libraries(sample_resnet PRIVATE "${TORCH_LIBRARIES}")
