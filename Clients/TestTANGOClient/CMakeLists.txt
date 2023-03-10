cmake_minimum_required(VERSION 3.24)
project(TestTANGOClient)

set(CMAKE_CXX_STANDARD 17)

set(TANGO_DIR /usr/local/tango)
set(TANGO_LIB_DIR ${TANGO_DIR}/lib)
set(TANGO_INCLUDE_DIR ${TANGO_DIR}/include/tango)

include_directories(${TANGO_INCLUDE_DIR})

add_executable(TestTANGOClient main.cpp)
target_link_libraries(TestTANGOClient ${TANGO_LIB_DIR}/libtango.so)
target_link_libraries(TestTANGOClient zmq omniORB4 omnithread)
