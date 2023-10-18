cmake_minimum_required(VERSION 3.5)
project(DiagramaT)
set(CMAKE_CXX_STANDARD 11)
set(SOURCES src/Interprete.cpp src/Programa.cpp src/ProgramaBase.cpp  src/Traductor.cpp
        src/ConexionLenguaje.cpp src/DiagramaT.cpp src/main.cpp)
set(HEADERS "headers/Interprete.hpp" "headers/Programa.hpp" "headers/ProgramaBase.hpp"
        "headers/Traductor.hpp" "headers/ConexionLenguaje.hpp" "headers/DiagramaT.hpp")
add_executable(DiagramaT ${SOURCES} ${HEADERS})

IF( test AND test STREQUAL "on" )
  set(CMAKE_CXX_FLAGS "--coverage -fprofile-arcs -ftest-coverage")
  message("Testing enabled")
  file(GLOB TEST_SRC_FILES src/Interprete.cpp src/Programa.cpp src/ProgramaBase.cpp  src/Traductor.cpp
          src/ConexionLenguaje.cpp src/DiagramaT.cpp src/test.cpp)
  add_subdirectory("ext/googletest")
  enable_testing()
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
  add_executable(runUnitTests ${TEST_SRC_FILES})
  target_link_libraries(runUnitTests gtest gtest_main)
  add_test(UnitTests runUnitTests)
ENDIF()