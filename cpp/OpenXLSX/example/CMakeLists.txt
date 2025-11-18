cmake_minimum_required(VERSION 3.16)
project(OpenXLSX-sample CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(OPENXLSX_CREATE_DOCS OFF CACHE BOOL "Disable OpenXLSX doc" FORCE)
set(OPENXLSX_BUILD_SAMPLES OFF CACHE BOOL "Disable OpenXLSX samples" FORCE)
set(OPENXLSX_BUILD_TESTS OFF CACHE BOOL "Disable OpenXLSX tests" FORCE)
set(OPENXLSX_BUILD_BENCHMARKS OFF CACHE BOOL "Disable OpenXLSX benchmarks" FORCE)
FetchContent_Declare(
  OpenXLSX
  GIT_REPOSITORY https://github.com/troldal/OpenXLSX.git
  GIT_TAG        master
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(OpenXLSX)

add_executable(example example.cc)
target_include_directories(example PRIVATE
  ${OpenXLSX_SOURCE_DIR}/OpenXLSX
)
target_link_libraries(example PRIVATE 
  OpenXLSX::OpenXLSX
)
