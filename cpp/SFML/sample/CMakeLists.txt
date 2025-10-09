cmake_minimum_required(VERSION 3.16)
project(SFML-sample C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        3.0.2
  GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(SFML)

include_directories(${SFML_SOURCE_DIR}/include)
include_directories(${SFML_SOURCE_DIR}/extlib/headers)

add_executable(sample sample.cc)
target_link_libraries(sample PRIVATE sfml-graphics sfml-window sfml-system)
