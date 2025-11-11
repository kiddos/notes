cmake_minimum_required(VERSION 3.16)
project(ncurses-example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

find_package(Curses REQUIRED)

add_executable(example example.cc)
target_link_libraries(example PRIVATE ${CURSES_LIBRARIES})
