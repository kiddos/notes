cmake_minimum_required(VERSION 3.16)
project(tesseract-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  CLI11
  GIT_REPOSITORY https://github.com/CLIUtils/CLI11
  GIT_TAG        v2.4.2
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(CLI11)

FetchContent_Declare(
  tesseract
  GIT_REPOSITORY https://github.com/tesseract-ocr/tesseract.git
  GIT_TAG        5.5.1
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(tesseract)

FetchContent_Declare(
  tesseract-best
  URL https://github.com/tesseract-ocr/tessdata_best/archive/refs/tags/4.1.0.tar.gz
)
FetchContent_MakeAvailable(tesseract-best)

add_executable(example example.cc)
target_include_directories(example PRIVATE
  ${CLI11_SOURCE_DIR}/include
  ${tesseract_SOURCE_DIR}/include
  ${tesseract_BINARY_DIR}/include
)
target_link_libraries(example PRIVATE
  CLI11
  libtesseract
)
