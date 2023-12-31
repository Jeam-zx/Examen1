cmake_minimum_required(VERSION 3.5)
project(diagramaT)
set(CMAKE_CXX_STANDARD 11)
set(SOURCES src/Vector3D.cpp src/main.cpp)
set(HEADERS "headers/Vector3D.hpp")
add_executable(vector3D ${SOURCES} ${HEADERS})

IF( test AND test STREQUAL "on" )
  set(CMAKE_CXX_FLAGS "--coverage -fprofile-arcs -ftest-coverage")
  message("Testing enabled")
  file(GLOB TEST_SRC_FILES src/Vector3D.cpp src/test.cpp)
  add_subdirectory("ext/googletest")
  enable_testing()
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
  add_executable(runUnitTests ${TEST_SRC_FILES})
  target_link_libraries(runUnitTests gtest gtest_main)
  add_test(UnitTests runUnitTests)
ENDIF()