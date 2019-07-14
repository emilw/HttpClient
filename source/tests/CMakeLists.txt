cmake_minimum_required (VERSION 2.6)
project (HttpClientTests)
include(ExternalProject)

#ExternalProject_Get_Property(bin_dir sourceFiles)

#foreach(sourceFile ${source_files})
#  set(sourceFile_val ../../${sourceFile})
#endforeach(sourceFile)

add_executable(HttpClientTests catch.hpp URLTests.cpp ../URL.h ../URL.cpp)
add_test("AllTests" ${CMAKE_BINARY_DIR}/HttpClientTests)
