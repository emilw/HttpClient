cmake_minimum_required (VERSION 2.6)
project (HttpClientTests)
include(ExternalProject)

#ExternalProject_Get_Property(bin_dir sourceFiles)

#foreach(sourceFile ${source_files})
#  set(sourceFile_val ../../${sourceFile})
#endforeach(sourceFile)

add_executable(../../../bin/HttpClientTests catch.hpp URLTests.cpp)
add_test("AllTests" ../../../bin/HttpClientTests)
