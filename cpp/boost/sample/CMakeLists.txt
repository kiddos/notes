cmake_minimum_required(VERSION 3.14)
project(boost-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)
FetchContent_Declare(
  boost
  URL    https://github.com/boostorg/boost/releases/download/boost-1.86.0/boost-1.86.0-cmake.tar.gz
)

FetchContent_MakeAvailable(boost)

add_executable(argument_parser_sample argument_parser_sample.cc)
target_link_libraries(argument_parser_sample PRIVATE Boost::program_options)

add_executable(filesystem_sample filesystem_sample.cc)
target_link_libraries(filesystem_sample PRIVATE Boost::filesystem)

add_executable(datetime_sample datetime_sample.cc)
target_link_libraries(datetime_sample PRIVATE Boost::date_time)

add_executable(echo_sample echo_sample.cc)
target_link_libraries(echo_sample PRIVATE Boost::system Boost::thread)

add_executable(regex_sample regex_sample.cc)
target_link_libraries(regex_sample PRIVATE Boost::system Boost::regex)
