cmake_minimum_required(VERSION 3.16)
project(spdlog-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG        v1.16.0
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(spdlog)

add_executable(example example.cc)
target_link_libraries(example PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)
