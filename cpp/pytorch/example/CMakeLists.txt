cmake_minimum_required(VERSION 3.16)
project(pytorch-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  libtorch
  URL https://download.pytorch.org/libtorch/cpu/libtorch-shared-with-deps-2.9.0%2Bcpu.zip
)
FetchContent_MakeAvailable(libtorch)

set(CMAKE_PREFIX_PATH "${libtorch_SOURCE_DIR}/share/cmake/Torch" ${CMAKE_PREFIX_PATH})
find_package(Torch REQUIRED)
find_package(Threads REQUIRED)

FetchContent_Declare(
  stb
  GIT_REPOSITORY https://github.com/nothings/stb
  GIT_TAG        master
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(stb)

add_executable(example example.cc)
target_link_libraries(example PRIVATE
  ${TORCH_LIBRARIES}
  Threads::Threads
)

add_executable(eval_example eval_example.cc)
target_link_libraries(eval_example PRIVATE
  ${TORCH_LIBRARIES}
  Threads::Threads
)

add_executable(resnet_example resnet_example.cc)
target_include_directories(resnet_example PRIVATE ${stb_SOURCE_DIR})
target_compile_options(resnet_example PRIVATE -DSTB_IMAGE_IMPLEMENTATION -DSTB_IMAGE_RESIZE_IMPLEMENTATION)
target_link_libraries(resnet_example PRIVATE
  ${TORCH_LIBRARIES}
  Threads::Threads
)
