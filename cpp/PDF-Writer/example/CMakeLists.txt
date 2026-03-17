cmake_minimum_required(VERSION 3.16)
project(pdf-writer-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  PDFHummus
  GIT_REPOSITORY https://github.com/galkahana/PDF-Writer.git
  GIT_TAG        v4.8.1
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(PDFHummus)

add_executable(example_write example_write.cc)
target_compile_options(example_write INTERFACE -Wall -Wextra)
target_link_libraries(example_write PDFHummus::PDFWriter)

add_executable(example_watermark example_watermark.cc)
target_compile_options(example_watermark INTERFACE -Wall -Wextra)
target_link_libraries(example_watermark PDFHummus::PDFWriter)

add_executable(example_parser example_parser.cc)
target_compile_options(example_parser INTERFACE -Wall -Wextra)
target_link_libraries(example_parser PDFHummus::PDFWriter)
