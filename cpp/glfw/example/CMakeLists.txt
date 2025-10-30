cmake_minimum_required(VERSION 3.16)
project(glfw-example LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Disable glfw examples" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Disable glfw tests" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Disable glfw docs" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "Disable glfw examples" FORCE)
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        3.4
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
  glad
  GIT_REPOSITORY https://github.com/Dav1dde/glad.git
  GIT_TAG v2.0.8
  GIT_SHALLOW
  GIT_PROGRESS   TRUE
  SOURCE_SUBDIR  cmake
)
FetchContent_MakeAvailable(glad)

glad_add_library(glad_gl_core_46 STATIC REPRODUCIBLE LOADER API gl:core=4.6)

find_package(OpenGL REQUIRED)

add_executable(example example.cc)

target_link_libraries(example
  PRIVATE
  glfw
  glad_gl_core_46
  OpenGL::GL
)

target_link_libraries(example PRIVATE dl pthread)
