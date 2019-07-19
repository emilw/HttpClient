cmake_minimum_required (VERSION 2.6)
project (HttpClientTests)
include(ExternalProject)

#ExternalProject_Get_Property(bin_dir sourceFiles)

#foreach(sourceFile ${source_files})
#  set(sourceFile_val ../../${sourceFile})
#endforeach(sourceFile)

add_executable(HttpClientTests catch.hpp URLTests.cpp CallTests.cpp ../URL.h ../URL.cpp ../StringBufferHelper.h ../StringBufferHelper.cpp ../Log.h ../Log.cpp ../TCPClient.h ../TCPClient.cpp ../HttpResponse.h ../HttpResponse.cpp ../HttpClient.h ../HttpClient.cpp)
add_test("all_tests" HttpClientTests)