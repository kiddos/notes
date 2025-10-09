cmake_minimum_required(VERSION 3.16)
project(clamav-sample C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

FetchContent_Declare(
  CLI11
  GIT_REPOSITORY https://github.com/CLIUtils/CLI11
  GIT_TAG        v2.4.2
  GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(CLI11)

include_directories(${CMAKE_BINARY_DIR}/_deps/clamav-build)

FetchContent_Declare(
  clamav
  URL https://www.clamav.net/downloads/production/clamav-1.5.0.tar.gz
)

set(ENABLE_CLAMAV OFF CACHE BOOL "Disable clamscan binary" FORCE)
set(ENABLE_MILTER OFF CACHE BOOL "Disable clamd-milter" FORCE)
set(ENABLE_APP OFF CACHE BOOL "Disable app" FORCE)
set(ENABLE_TESTS OFF CACHE BOOL "Disable tests" FORCE)
FetchContent_MakeAvailable(clamav)

include_directories(
  ${clamav_SOURCE_DIR}/libclamav
  ${clamav_BINARY_DIR}
  ${clamav_BINARY_DIR}/libclamav
  ${CLI11_SOURCE_DIR}/include
)

add_executable(sample sample.cc)
target_link_libraries(sample PRIVATE clamav)
