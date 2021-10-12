cmake_minimum_required(VERSION 3.16)

project(test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

find_package(Threads REQUIRED)

set(LIB_MEMORY mem_operations.c)
add_library(mem_operations STATIC ${LIB_MEMORY})

set(LIB_CHECK correct_input.c)
add_library(correct_input STATIC ${LIB_CHECK})

set(LIB_IN in_hand.c)
add_library(in_hand STATIC ${LIB_IN})

add_executable(main main.c out_hand.c search.c)
target_link_libraries(main correct_input mem_operations in_hand)
