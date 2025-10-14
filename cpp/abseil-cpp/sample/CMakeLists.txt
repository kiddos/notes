cmake_minimum_required(VERSION 3.16)
project(project CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(BUILD_SHARED_LIBS OFF)

include(FetchContent)

FetchContent_Declare(
  abseil
  GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
  GIT_TAG        20250512.0
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(abseil)

add_executable(sample sample.cc)
target_link_libraries(sample PRIVATE
  absl::strings
  absl::flat_hash_map)
