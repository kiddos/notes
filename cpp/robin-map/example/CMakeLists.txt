cmake_minimum_required(VERSION 3.16)
project(robin-map-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  robin_map
  GIT_REPOSITORY https://github.com/Tessil/robin-map.git
  GIT_TAG        v1.4.1
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(robin_map)

add_executable(example example.cc)
target_include_directories(example PRIVATE ${robin_map_SOURCE_DIR}/include)
target_link_libraries(example PRIVATE tsl::robin_map)
