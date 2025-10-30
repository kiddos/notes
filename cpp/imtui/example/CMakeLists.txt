cmake_minimum_required(VERSION 3.14)
project(imtui-example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

FetchContent_Declare(
  imtui
  GIT_REPOSITORY https://github.com/ggerganov/imtui
  GIT_TAG        v1.0.5
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(imtui)

include_directories(${imtui_SOURCE_DIR}/include/imtui)
message("${imtui_SOURCE_DIR}/include")

add_executable(example example.cc)
target_link_libraries(example PRIVATE imtui imtui-ncurses)
