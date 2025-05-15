cmake_minimum_required(VERSION 3.14)
project(openssl-sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(FETCHCONTENT_QUIET FALSE)

find_package(OpenSSL REQUIRED)  
  
# Output status message about found OpenSSL  
message(STATUS "Found OpenSSL ${OPENSSL_VERSION}")  
message(STATUS "OpenSSL include dir: ${OPENSSL_INCLUDE_DIR}")  
message(STATUS "OpenSSL libraries: ${OPENSSL_LIBRARIES}")

# Create your executable
add_executable(sample sample.cc)

# Link against OpenSSL libraries
target_link_libraries(sample PRIVATE
  OpenSSL::SSL OpenSSL::Crypto
)
