cmake_minimum_required(VERSION 3.14)
project(sdl3-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

FetchContent_Declare(
  sdl3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL
  GIT_TAG        release-3.2.0
  GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(sdl3)

add_executable(sample sample.cc)
target_link_libraries(sample SDL3::SDL3)
