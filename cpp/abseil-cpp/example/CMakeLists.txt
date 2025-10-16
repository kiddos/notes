cmake_minimum_required(VERSION 3.16)
project(abseil-cpp-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(BUILD_SHARED_LIBS OFF)

FetchContent_Declare(
  abseil
  GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
  GIT_TAG        20250512.0
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(abseil)

add_executable(strings_example strings_example.cc)
target_link_libraries(strings_example PRIVATE absl::strings)

add_executable(container_example container_example.cc)
target_link_libraries(container_example PRIVATE absl::flat_hash_map)

add_executable(log_example log_example.cc)
target_link_libraries(log_example PRIVATE
  absl::log
  absl::log_initialize)
