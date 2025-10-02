cmake_minimum_required(VERSION 3.14)
project(ncurses-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

find_package(Curses REQUIRED)

add_executable(sample sample.cc)
target_link_libraries(sample PRIVATE ${CURSES_LIBRARIES})
