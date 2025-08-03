cmake_minimum_required(VERSION 3.14)
project(openssl-sample C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)
include(ExternalProject)

FetchContent_Declare(
  openssl
  GIT_REPOSITORY https://github.com/openssl/openssl
  GIT_TAG        openssl-3.5.1
  GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(openssl)

set(OPENSSL_BUILD_DIR "${CMAKE_BINARY_DIR}/openssl-build")
set(OPENSSL_INSTALL_PREFIX "${OPENSSL_BUILD_DIR}/openssl")
ExternalProject_Add(openssl_external_project
  SOURCE_DIR "${openssl_SOURCE_DIR}"
  BINARY_DIR "${OPENSSL_BUILD_DIR}"
  CONFIGURE_COMMAND perl "${openssl_SOURCE_DIR}/Configure" -static -no-docs --prefix=${OPENSSL_INSTALL_PREFIX}
  BUILD_COMMAND make -j8
  INSTALL_COMMAND make install
  BUILD_BYPRODUCTS
      "${OPENSSL_INSTALL_PREFIX}/lib64/libssl.a"
      "${OPENSSL_INSTALL_PREFIX}/lib64/libcrypto.a"
)

add_executable(sample sample.cc)
target_link_libraries(sample PRIVATE
  "${OPENSSL_INSTALL_PREFIX}/lib64/libssl.a"
  "${OPENSSL_INSTALL_PREFIX}/lib64/libcrypto.a"
  dl
)

# find_package(OpenSSL REQUIRED)
# message(STATUS "Found OpenSSL ${OPENSSL_VERSION}")  
# message(STATUS "OpenSSL include dir: ${OPENSSL_INCLUDE_DIR}")  
# message(STATUS "OpenSSL libraries: ${OPENSSL_LIBRARIES}")
# target_link_libraries(sample PRIVATE
#   OpenSSL::SSL OpenSSL::Crypto dl
# )

add_dependencies(sample openssl_external_project)
