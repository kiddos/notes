cmake_minimum_required(VERSION 3.16)
project(workflow-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
# set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  workflow
  GIT_REPOSITORY https://github.com/sogou/workflow.git
  GIT_TAG        v0.11.11
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(workflow)

add_executable(example example.cc)
target_include_directories(example PRIVATE
  ${workflow_SOURCE_DIR}/src/include
)
target_link_libraries(example PRIVATE workflow-static)
