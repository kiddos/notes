cmake_minimum_required(VERSION 3.14)
project(nbody)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

find_package(OpenGL REQUIRED)

FetchContent_Declare(
  sdl3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL
  GIT_TAG        release-3.2.0
  GIT_SHALLOW    TRUE
)

FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm
  GIT_TAG        1.0.1
  GIT_SHALLOW    TRUE
)

FetchContent_Declare(
  glew
  URL https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0.zip
  URL_HASH SHA256=a9046a913774395a095edcc0b0ac2d81c3aacca61787b39839b941e9be14e0d4
)

FetchContent_MakeAvailable(sdl3 glm glew)

include_directories(${glm_SOURCE_DIR})
include_directories(${glew_SOURCE_DIR}/include)

add_library(glew STATIC
  ${glew_SOURCE_DIR}/src/glew.c
  ${glew_SOURCE_DIR}/src/glewinfo.c
  ${glew_SOURCE_DIR}/src/visualinfo.c
)
target_compile_definitions(glew PRIVATE GLEW_STATIC)
target_link_libraries(glew PRIVATE OpenGL::OpenGL GL)

add_executable(main
  main.cc
  window.cc
  particle.cc
  particle_system.cc
  simulation.cc
)
add_dependencies(main glm)
target_link_libraries(main PRIVATE SDL3::SDL3 OpenGL::OpenGL ${CMAKE_DL_LIBS} glew)

file(GLOB SHADER_FILES "${CMAKE_SOURCE_DIR}/shaders/*.glsl")
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/shaders)
foreach(SHADER ${SHADER_FILES})
  configure_file(${SHADER} ${CMAKE_BINARY_DIR}/shaders COPYONLY)
endforeach()
