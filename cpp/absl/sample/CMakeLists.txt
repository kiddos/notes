cmake_minimum_required(VERSION 3.14)
project(absl-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build static libraries" FORCE)

include(FetchContent)

# Fetch Abseil
FetchContent_Declare(
  abseil
  GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
  GIT_TAG        20250512.0
)

# Make RE2 available
FetchContent_MakeAvailable(abseil)

# Create your executable
add_executable(sample sample.cc)

# Link against RE2
target_link_libraries(sample PRIVATE absl::strings)
