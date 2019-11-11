cmake_minimum_required(VERSION 2.8.12.2)
#
ADD_DEFINITIONS(-DLINUX)
#
INCLUDE_DIRECTORIES(../libmisc-cpp)
INCLUDE_DIRECTORIES(../libxsc-cpp)
INCLUDE_DIRECTORIES(../libxsc-proto-cpp)
INCLUDE_DIRECTORIES(../libx-msg-im-xsc)
#
INCLUDE_DIRECTORIES($ENV{PROTOBUF}/include)
#
ADD_COMPILE_OPTIONS(-std=c++17 -fPIC -Wall)
ADD_DEFINITIONS(-Wno-builtin-macro-redefined)
SET(CMAKE_CXX_FLAGS $ENV{CXX_FLAGS})
#
LINK_DIRECTORIES(../libmisc-cpp)
LINK_DIRECTORIES(../libxsc-cpp)
LINK_DIRECTORIES(../libxsc-proto-cpp)
LINK_DIRECTORIES(../libx-msg-im-xsc)
#
LINK_DIRECTORIES($ENV{PROTOBUF}/lib)
#
LINK_LIBRARIES(x-msg-im-xsc)
LINK_LIBRARIES(xsc-proto-cpp)
LINK_LIBRARIES(xsc-cpp)
LINK_LIBRARIES(misc-cpp)
LINK_LIBRARIES(libprotobuf.a)
LINK_LIBRARIES(uuid)
LINK_LIBRARIES(pthread)
#
FILE(GLOB SRC0 "./*.cpp")
FILE(GLOB SRC1 "./*.cc")
#
PROJECT(x-msg-im-xsc-exapmples-cpp)
#
ADD_EXECUTABLE(x-msg-im-xsc-exapmples-cpp ${SRC0} ${SRC1})
INCLUDE(./__file__.cmake)
REDEFINE_FILE_MACRO(x-msg-im-xsc-exapmples-cpp)

