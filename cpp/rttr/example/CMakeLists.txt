cmake_minimum_required(VERSION 3.16)
project(rttr-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  rttr
  GIT_REPOSITORY https://github.com/rttrorg/rttr.git
  GIT_TAG        master
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
set(BUILD_PACKAGE OFF CACHE BOOL "Disable rttr package" FORCE)
set(BUILD_INSTALLER OFF CACHE BOOL "Disable rttr installer" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "Disable rttr examples" FORCE)
set(BUILD_UNIT_TESTS OFF CACHE BOOL "Disable rttr unit tests" FORCE)
set(BUILD_DOCUMENTATION OFF CACHE BOOL "Disable rttr documentation" FORCE)
FetchContent_MakeAvailable(rttr)

add_executable(example example.cc)
target_include_directories(example PRIVATE ${rttr_SOURCE_DIR}/src)
target_link_libraries(example PRIVATE RTTR::Core)
