cmake_minimum_required(VERSION 3.16)
project(libexpat-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(EXPAT_BUILD_EXAMPLES OFF CACHE BOOL "Disable libexpat examples" FORCE)
set(EXPAT_BUILD_TESTS OFF CACHE BOOL "Disable libexpat tests" FORCE)
set(EXPAT_BUILD_TOOLS OFF CACHE BOOL "Disable libexpat tools" FORCE)

FetchContent_Declare(
  libexpat
  GIT_REPOSITORY https://github.com/libexpat/libexpat.git
  SOURCE_SUBDIR  expat/
  GIT_TAG        R_2_7_3
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(libexpat)

FetchContent_Declare(
  CLI11
  GIT_REPOSITORY https://github.com/CLIUtils/CLI11
  GIT_TAG        v2.4.2
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(CLI11)


add_executable(example example.cc)
target_include_directories(example PRIVATE ${CLI11_SOURCE_DIR}/include)
target_link_libraries(example PUBLIC
  expat::expat
  CLI11)
