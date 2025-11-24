cmake_minimum_required(VERSION 3.16)
project(json-c-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(BUILD_APPS ON CACHE BOOL "Disable json-c apps" FORCE)
FetchContent_Declare(
  jsonc
  GIT_REPOSITORY https://github.com/json-c/json-c.git
  GIT_TAG        master
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(jsonc)

add_executable(example example.c)
target_include_directories(example PRIVATE ${jsonc_SOURCE_DIR})
target_link_libraries(example PRIVATE json-c)
