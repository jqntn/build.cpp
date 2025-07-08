cmake_minimum_required (VERSION 3.8)

project ("hello")

add_executable (hello "hello.cpp" "hello.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET hello PROPERTY CXX_STANDARD 20)
endif()