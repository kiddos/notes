cmake_minimum_required(VERSION 3.14)
project(openssl-example C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)
include(ExternalProject)

set(OPENSSL_BUILD_DIR "${CMAKE_BINARY_DIR}/openssl-build")
set(OPENSSL_INSTALL_PREFIX "${OPENSSL_BUILD_DIR}/openssl")
ExternalProject_Add(openssl_local
  URL               https://github.com/openssl/openssl/releases/download/openssl-3.6.1/openssl-3.6.1.tar.gz
  # GIT_REPOSITORY    https://github.com/openssl/openssl
  # GIT_TAG           openssl-3.6.1
  BUILD_IN_SOURCE   TRUE
  CONFIGURE_COMMAND <SOURCE_DIR>/Configure
                    --prefix=${OPENSSL_INSTALL_PREFIX}
                    no-shared
  BUILD_COMMAND     make -j8
  INSTALL_COMMAND   make install_sw
  CONFIGURE_HANDLED_BY_BUILD ON
)

add_executable(example example.cc)
add_dependencies(example openssl_local)
target_include_directories(example PRIVATE
  ${OPENSSL_INSTALL_PREFIX}/include
)
target_link_directories(example PRIVATE
  ${OPENSSL_INSTALL_PREFIX}/lib
)
target_link_libraries(example PRIVATE
  ssl
  crypto
)
