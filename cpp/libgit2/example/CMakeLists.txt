cmake_minimum_required(VERSION 3.16)
project(libgit2-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
  libgit2
  GIT_REPOSITORY https://github.com/libgit2/libgit2.git
  GIT_TAG        v1.9.1
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
set(BUILD_TESTS OFF CACHE BOOL "Disable libgit2 tests" FORCE)
set(BUILD_CLI OFF CACHE BOOL "Disable libgit2 cli" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "Disable libgit2 example" FORCE)
set(BUILD_FUZZERS OFF CACHE BOOL "Disable libgit2 fuzzers" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Disable libgit2 shared libs" FORCE)
FetchContent_MakeAvailable(libgit2)

FetchContent_Declare(
  CLI11
  GIT_REPOSITORY https://github.com/CLIUtils/CLI11
  GIT_TAG        v2.4.2
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(CLI11)

add_executable(example example.cc)
add_dependencies(example libgit2)
target_include_directories(example PRIVATE
  ${CLI11_SOURCE_DIR}/include
  ${libgit2_SOURCE_DIR}/include
  ${libgit2_BINARY_DIR}/include
)
target_link_libraries(example PRIVATE
  git2
  CLI11
)
target_link_directories(example PRIVATE 
  ${libgit2_BINARY_DIR}
)
