cmake_minimum_required(VERSION 3.14)
project(curl-sample C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)
include(ExternalProject)

set(OPENSSL_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/openssl/install")
set(OPENSSL_SOURCE_DIR "${CMAKE_BINARY_DIR}/openssl/src/openssl")
ExternalProject_Add(openssl
  PREFIX ${CMAKE_BINARY_DIR}/openssl
  URL https://github.com/openssl/openssl/releases/download/openssl-3.6.0/openssl-3.6.0.tar.gz
  CONFIGURE_COMMAND ${OPENSSL_SOURCE_DIR}/Configure no-dso no-shared --prefix=${OPENSSL_INSTALL_PREFIX}
  BUILD_COMMAND make -j8
  INSTALL_COMMAND make install_sw
)

set(LIBCURL_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/curl")
ExternalProject_Add(libcurl
  PREFIX ${CMAKE_BINARY_DIR}/curl
  GIT_REPOSITORY https://github.com/curl/curl.git
  GIT_TAG        curl-8_17_0
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
  CMAKE_ARGS
    -DCMAKE_USE_OPENSSL=ON
    -DBUILD_STATIC_LIBS=ON
    -DBUILD_STATIC_CURL=ON
    -DOPENSSL_ROOT_DIR=${OPENSSL_INSTALL_PREFIX}
    -DCMAKE_INSTALL_PREFIX=${LIBCURL_INSTALL_PREFIX}
  DEPENDS openssl
)
add_dependencies(libcurl openssl)

add_executable(example example.cc)
target_include_directories(example PRIVATE
  ${LIBCURL_INSTALL_PREFIX}/include
)
target_link_directories(example PRIVATE
  ${LIBCURL_INSTALL_PREFIX}/lib
)
target_link_libraries(example PRIVATE
  curl
)
add_dependencies(example libcurl)
