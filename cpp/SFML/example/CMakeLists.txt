cmake_minimum_required(VERSION 3.16)
project(SFML-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        3.0.2
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(SFML)

add_executable(example example.cc)
target_include_directories(example PRIVATE
  ${SFML_SOURCE_DIR}/include
  ${SFML_SOURCE_DIR}/extlib/headers
)
target_link_libraries(example PRIVATE
  sfml-graphics
  sfml-window
  sfml-system
)
