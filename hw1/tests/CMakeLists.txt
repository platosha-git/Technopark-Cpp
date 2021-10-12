cmake_minimum_required(VERSION 3.16)

project(test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

find_package(Threads REQUIRED)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(correct_test correct_test.cpp)
target_link_libraries(correct_test ${GTEST_LIBRARIES} Threads::Threads)

add_executable(mem_test mem_test.cpp)
target_link_libraries(mem_test ${GTEST_LIBRARIES} Threads::Threads)
