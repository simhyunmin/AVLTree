cmake_minimum_required(VERSION 3.13)

project(GoogleTestSimple)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
message("GTest_INCLUDE_DIRS = ${GTest_INCLUDE_DIRS}")

add_library(common_library AvlTree/AvlTree.cpp AvlTree/AvlTreeMetrics.cpp AvlTree/AvlTreeRotate.cpp AvlTree/AvlTreeUtils)

add_executable(mainApp AvlTree/main.cpp)
target_link_libraries(mainApp common_library)

add_executable(functionTestRunner GoogleTest/function_test_runner.cc)
target_link_libraries(functionTestRunner common_library ${GTEST_LIBRARIES} pthread)

add_executable(totalTestRunner GoogleTest/total_test_runner.cc)
target_link_libraries(totalTestRunner common_library ${GTEST_LIBRARIES} pthread)

