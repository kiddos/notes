cmake_minimum_required(VERSION 3.14)
project(sentencepiece-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

FetchContent_Declare(
  sentencepiece
  GIT_REPOSITORY https://github.com/google/sentencepiece
  GIT_TAG        v0.2.0
  GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(sentencepiece)

include_directories(${sentencepiece_SOURCE_DIR}/src)

add_executable(sample sample.cc)
target_link_libraries(sample PRIVATE sentencepiece)
