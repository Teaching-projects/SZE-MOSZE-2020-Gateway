cmake_minimum_required(VERSION 2.6)
project(basic_test)
set (CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
add_executable(runTests jsontest.cpp ../JSON.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
