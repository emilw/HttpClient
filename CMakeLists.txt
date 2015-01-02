cmake_minimum_required (VERSION 2.6)
project (HttpClient)
set(source_dir source/)
set(bin_dir ../bin/)
set(source_files ${source_dir}main.cpp source/HttpClient.cpp ${source_dir}HttpResponse.cpp ${source_dir}TCPClient.cpp ${source_dir}StringBufferHelper.cpp ${source_dir}URL.cpp ${source_dir}Log.cpp)
add_executable(${bin_dir}HttpClient ${source_files})
#${source_dir}main.cpp source/HttpClient.cpp ${source_dir}HttpResponse.cpp ${source_dir}TCPClient.cpp ${source_dir}StringBufferHelper.cpp ${source_dir}URL.cpp ${source_dir}Log.cpp)
add_definitions(-std=c++11)

enable_testing(true)
add_subdirectory(${source_dir}tests)
include_directories(${source_dir}tests)

