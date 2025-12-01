cmake_minimum_required(VERSION 3.16)
project(dcmtk-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  dcmtk
  GIT_REPOSITORY https://github.com/DCMTK/dcmtk.git
  GIT_TAG        DCMTK-3.6.9
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(dcmtk)

FetchContent_Declare(
  CLI11
  GIT_REPOSITORY https://github.com/CLIUtils/CLI11
  GIT_TAG        v2.4.2
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(CLI11)

add_executable(example example.cc)
target_include_directories(example PRIVATE
  ${dcmtk_SOURCE_DIR}/dcmdata/include
  ${dcmtk_SOURCE_DIR}/config/include
  ${dcmtk_BINARY_DIR}/config/include
  ${dcmtk_SOURCE_DIR}/ofstd/include
  ${dcmtk_SOURCE_DIR}/oflog/include
  ${CLI11_SOURCE_DIR}/include
)
target_link_libraries(example PRIVATE
  dcmdata
  ofstd
  oflog
)
