cmake_minimum_required(VERSION 3.19)
project(ProgressiveLeetCode)

set(CMAKE_CXX_STANDARD 20)

message(Working\ directory:\ ${CMAKE_CURRENT_SOURCE_DIR})
file (GLOB files LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
foreach (file ${files})
    message(File\ name:\ ${file})
    string(REGEX REPLACE "(.+)\\.cpp" "\\1" executable ${file})
    message(${executable})
    add_executable (${executable} ${file})
    message (\ \ \ \ --\ ${file}.cpp\ will\ be\ compiled\ to\ ${executable})
endforeach ()