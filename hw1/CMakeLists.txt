cmake_minimum_required(VERSION 3.16)

project(test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

find_package(Threads REQUIRED)

set(LIB_SOURCE_FILES mem_operations.c)
add_library(mem_operations STATIC ${LIB_SOURCE_FILES})

set(LIB_SOURCE_FILES correct_input.c)
add_library(correct_input STATIC ${LIB_SOURCE_FILES})

set(LIB_SOURCE_FILES in_hand.c)
add_library(in_hand STATIC ${LIB_SOURCE_FILES})

add_executable(main main.c out_hand.c search.c)
target_link_libraries(main correct_input mem_operations in_hand)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(correct_test tests/correct_test.cpp)
target_link_libraries(correct_test ${GTEST_LIBRARIES} correct_input Threads::Threads)

add_executable(mem_test tests/mem_test.cpp)
target_link_libraries(mem_test ${GTEST_LIBRARIES} mem_operations Threads::Threads)
