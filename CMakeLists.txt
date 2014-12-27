cmake_minimum_required (VERSION 2.6)
project (HttpClient)
add_executable(../bin/HttpClient source/main.cpp source/HttpClient.cpp source/HttpResponse.cpp source/TCPClient.cpp source/StringBufferHelper.cpp source/URL.cpp)
add_definitions(-std=c++11)
