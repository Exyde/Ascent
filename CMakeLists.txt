cmake_minimum_required(VERSION 3.17)

project(test LANGUAGES CXX)

add_executable(ascent main.cpp)
target_link_libraries(ascent glfw GLEW /usr/lib/x86_64-linux-gnu/libGL.so.1 )