#=============================================================================
#
# file :        CMakeLists.txt
#
# description : File to generate a TANGO device server using cmake.
#
# project :     Camera
#
#=============================================================================
#                This file is generated by POGO
#        (Program Obviously used to Generate tango Object)
#=============================================================================
#
#

cmake_minimum_required (VERSION 3.20)
set(CMAKE_SKIP_RPATH TRUE)

# MAKE_ENV is the path to find common environment to build project
#
set(MAKE_ENV /usr/local/tango/share/pogo/preferences)
#
# Project definitions
#
project(Camera)
add_definitions(-DPCO_LINUX)

#
# optional compiler flags
#
set(CXXFLAGS_USER -g)

#
# Get global information
#
include(${MAKE_ENV}/cmake_tango.opt)

#
# Files for Camera TANGO class
#
set(CAMERA Camera)
set(CAMERA_INCLUDE ${CMAKE_SOURCE_DIR})
set(CAMERA_SRC  ${CAMERA}.cpp
                ${CAMERA}Class.cpp
                ${CAMERA}StateMachine.cpp)

#
# User additional include, link folders/libraries and source files
#
set(PCO_CPP_DIR /opt/pco/pco.cpp)
set(USER_INCL_DIR ${PCO_CPP_DIR}/runtime/include ${PCO_CPP_DIR}/pco.camera)
set(USER_LIB_DIR ${PCO_CPP_DIR}/bin64)
set(USER_LIBS pcocam_usb pco_sc2cam pcocom pcocom_usb pco_recorder pco_convert)
set(USER_SRC_FILES
        ${PCO_CPP_DIR}/pco.camera/camera.cpp
        ${PCO_CPP_DIR}/pco.camera/cameraexception.cpp
        ${PCO_CPP_DIR}/pco.camera/stdafx.cpp
        ${PCO_CPP_DIR}/pco.camera/image.cpp)
#
# Set global info and include directories
#
set(ALL_CLASS_INCLUDE  ${CAMERA_INCLUDE}  ${USER_INCL_DIR})
set(SERVER_SRC ${CAMERA_SRC} ${USER_SRC_FILES} ClassFactory.cpp main.cpp)
include_directories(${ALL_CLASS_INCLUDE} ${USER_INCL_DIR} ${TANGO_INCLUDES})

#
# Device Server generation
#
set(SERVER_NAME Camera)

#
#	Set library directories
#
link_directories(${USER_LIB_DIR} ${TANGO_LIB_HOME})

#
#	Compile and link
#
message("SERVER_NAME=${SERVER_NAME}")
message("SERVER_SRC=${SERVER_SRC}")
add_executable(${SERVER_NAME} ${SERVER_SRC})
target_link_libraries(${SERVER_NAME} ${USER_LIBS} ${TANGO_LIBS})


