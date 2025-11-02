cmake_minimum_required(VERSION 3.16)
project(libuvc-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(BUILD_EXAMPLE ON CACHE BOOL "Disable libuvc example" FORCE)
FetchContent_Declare(
  libuvc
  GIT_REPOSITORY https://github.com/libuvc/libuvc.git
  GIT_TAG        v0.0.7
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(libuvc)

add_executable(libuvc-example example.cc)
target_include_directories(libuvc-example PRIVATE ${libuvc_SOURCE_DIR}/include)
target_link_libraries(libuvc-example PRIVATE LibUVC::UVC)
