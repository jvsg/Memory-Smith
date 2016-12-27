cmake_minimum_required(VERSION 3.5)
project(Memory_Tinkerer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cxx src/target.cxx src/target.hxx src/debugger.cxx src/debugger.hxx src/log.hxx src/log.cxx)
add_executable(Memory_Tinkerer ${SOURCE_FILES})
