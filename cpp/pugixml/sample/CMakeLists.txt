cmake_minimum_required(VERSION 3.16)
project(pugixml-sample C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  pugixml
  GIT_REPOSITORY https://github.com/zeux/pugixml.git
  GIT_TAG        v1.15
  GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(pugixml)

add_executable(sample sample.cc)
target_include_directories(sample PRIVATE ${pugixml_SOURCE_DIR}/src)
target_link_libraries(sample PRIVATE pugixml::pugixml)
