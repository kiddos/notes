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
ExternalProject_Add(openssl_external_project
  URL               https://github.com/openssl/openssl/releases/download/openssl-3.6.0/openssl-3.6.0.tar.gz
  BUILD_IN_SOURCE   TRUE
  CONFIGURE_COMMAND sh -c "test ./Makefile || ./Configure -static -no-docs --prefix=${OPENSSL_INSTALL_PREFIX}"
  BUILD_COMMAND     $(MAKE) -j8
  INSTALL_COMMAND   $(MAKE) install
)

add_executable(example example.cc)
add_dependencies(example openssl_external_project)
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


# or find local OpenSSL
# find_package(OpenSSL REQUIRED)
# message(STATUS "Found OpenSSL ${OPENSSL_VERSION}")  
# message(STATUS "OpenSSL include dir: ${OPENSSL_INCLUDE_DIR}")  
# message(STATUS "OpenSSL libraries: ${OPENSSL_LIBRARIES}")
# target_link_libraries(example PRIVATE
#   OpenSSL::SSL OpenSSL::Crypto dl
# )
