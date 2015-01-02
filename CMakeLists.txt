cmake_minimum_required (VERSION 2.6)
project (HttpClient)
add_executable(HttpClient source/main.cpp source/HttpClient.cpp source/HttpResponse.cpp source/TCPClient.cpp source/StringBufferHelper.cpp source/URL.cpp source/Log.cpp)
add_definitions(-std=c++11)

if(WIN32)
    target_link_libraries(HttpClient ws2_32)
else()
endif()