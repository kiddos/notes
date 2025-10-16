cmake_minimum_required(VERSION 3.16)
project(boost-example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(BUILD_TESTING OFF CACHE BOOL "Disable boost tests" FORCE)
FetchContent_Declare(
  boost
  URL    https://github.com/boostorg/boost/releases/download/boost-1.89.0/boost-1.89.0-cmake.7z
)
FetchContent_MakeAvailable(boost)

# argument parsing
add_executable(argument_parser_example argument_parser_example.cc)
target_link_libraries(argument_parser_example PRIVATE Boost::program_options)

# filesystem
add_executable(filesystem_example filesystem_example.cc)
target_link_libraries(filesystem_example PRIVATE Boost::filesystem)

# datetime
add_executable(datetime_example datetime_example.cc)
target_link_libraries(datetime_example PRIVATE Boost::date_time)

# asio
add_executable(echo_example echo_example.cc)
target_link_libraries(echo_example PRIVATE Boost::asio Boost::thread)

# regex
add_executable(regex_example regex_example.cc)
target_link_libraries(regex_example PRIVATE Boost::regex)

# atomic
add_executable(atomic_example atomic_example.cc)
target_link_libraries(atomic_example PRIVATE Boost::atomic Boost::thread)

# uuid
add_executable(uuid_example uuid_example.cc)
target_link_libraries(uuid_example PRIVATE Boost::uuid)

# string
add_executable(string_example string_example.cc)
target_link_libraries(string_example PRIVATE Boost::algorithm)
