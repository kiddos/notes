cmake_minimum_required(VERSION 3.14)
project(qt-qml-sample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "/opt/Qt/6.9.1/gcc_64" ${CMAKE_PREFIX_PATH})

find_package(Qt6 COMPONENTS Core Gui Qml Quick REQUIRED)
message(STATUS "Qt6 version found: ${Qt6_VERSION}")
get_target_property(QT_CORE_INCLUDE_DIRS Qt6::Core INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "Qt6 Core include directories: ${QT_CORE_INCLUDE_DIRS}")

set(APP_SOURCES sample.cc qml.qrc)

add_executable(sample ${APP_SOURCES})

target_include_directories(sample PRIVATE
  /opt/Qt/6.9.1/gcc_64/include
)

target_link_libraries(sample PRIVATE
  Qt6::Core
  Qt6::Gui
  Qt6::Qml
  Qt6::Quick
)
