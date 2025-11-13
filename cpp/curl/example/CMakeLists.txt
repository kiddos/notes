cmake_minimum_required(VERSION 3.16)
project(curl-example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

set(BUILD_STATIC_LIBS ON CACHE BOOL "Enable curl static build" FORCE)
set(BUILD_STATIC_CURL ON CACHE BOOL "Enable curl static build" FORCE)
set(CURL_DISABLE_INSTALL ON CACHE BOOL "Disable curl install" FORCE)
set(ENABLE_DEBUG OFF CACHE BOOL "Disable curl debug" FORCE)
set(BUILD_LIBCURL_DOCS OFF CACHE BOOL "Disable libcurl doc" FORCE)
set(BUILD_MISC_DOCS OFF CACHE BOOL "Disable libcurl misc doc" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "Disable curl example" FORCE)
set(CURL_BUILD_TESTING CACHE BOOL "Disable curl testing" FORCE)
FetchContent_Declare(
  curl
  GIT_REPOSITORY https://github.com/curl/curl.git
  GIT_TAG        curl-8_17_0
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)

FetchContent_MakeAvailable(curl)

add_executable(example example.cc)
target_link_libraries(example PRIVATE libcurl)
