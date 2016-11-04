cmake_minimum_required(VERSION 3.5)
project(Memory_Tinkerer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11")

set(SOURCE_FILES src/main.c src/target.c src/target.h src/debugger.c src/debugger.h src/log.h src/log.c)
add_executable(Memory_Tinkerer ${SOURCE_FILES})
