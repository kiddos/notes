cmake_minimum_required(VERSION 3.16)
project(imgui-glfw-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Disable glfw examples" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Disable glfw tests" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Disable glfw docs" FORCE)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        3.4
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui
  GIT_TAG        docking
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(imgui glfw)

find_package(OpenGL REQUIRED)
find_package(X11 REQUIRED)

add_executable(example
  example.cc
  ${imgui_SOURCE_DIR}/imgui.cpp
  ${imgui_SOURCE_DIR}/imgui_demo.cpp
  ${imgui_SOURCE_DIR}/imgui_draw.cpp
  ${imgui_SOURCE_DIR}/imgui_tables.cpp
  ${imgui_SOURCE_DIR}/imgui_widgets.cpp
  ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
  ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)

target_include_directories(example PRIVATE
  ${imgui_SOURCE_DIR}
  ${imgui_SOURCE_DIR}/backends
)

target_link_libraries(example PRIVATE
  glfw
  dl
  OpenGL::OpenGL
  ${X11_LIBRARIES}
)
