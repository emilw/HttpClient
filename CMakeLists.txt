cmake_minimum_required (VERSION 2.6)
project (HttpClient)
set(source_dir source/)
#set(CMAKE_BINARY_DIR "${PROJECT_SOURCE_DIR}/bin")
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(source_files ${source_dir}main.cpp source/HttpClient.cpp ${source_dir}HttpResponse.cpp ${source_dir}TCPClient.cpp ${source_dir}StringBufferHelper.cpp ${source_dir}URL.cpp ${source_dir}Log.cpp)
add_executable(HttpClient ${source_files})
add_definitions(-std=c++11)
include_directories(.)

if(WIN32)
    target_link_libraries(HttpClient ws2_32)
else()
endif()

enable_testing(true)
add_subdirectory(${source_dir}tests)
#add_subdirectory(${CMAKE_BINARY_DIR})
#include_directories(tests)