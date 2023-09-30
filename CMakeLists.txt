cmake_minimum_required(VERSION 3.17)

#Project Name
project(Ascent)

#Setting up output directories - Not working yet... Aniway, lets move on for today
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/obj) #.a, .o
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) #dll
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/runtime)

# Specify the directory for object files
set(CMAKE_OBJECT_PATH_MAX 1)  # To make sure object files go to the obj directory

#Packages Search
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLUT REQUIRED)

#Setting All sources
file(GLOB_RECURSE SOURCES "src/*.cpp")

#set(SOURCES
#    src/main.cpp
#    src/shaders/shader.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} glfw GLEW /usr/lib/x86_64-linux-gnu/libGL.so.1 )

#IF NEEDED
# Inclusion des en-têtes et des bibliothèques OpenGL, GLEW et GLUT
#target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

# Liaison des bibliothèques OpenGL, GLEW et GLUT
#target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${GLUT_LIBRARIES})
