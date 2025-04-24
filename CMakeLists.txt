# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Name your project
project(MyGLFWProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify paths for GLFW
set(GLFW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/ext/include")
set(GLFW_LIBRARY "${CMAKE_SOURCE_DIR}/ext/lib/libglfw3.a")

# Find OpenGL (required by GLFW)
find_package(OpenGL REQUIRED)

# Recursively collect all .cpp and .hpp files in the src directory and subdirectories
file(GLOB_RECURSE PROJECT_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE PROJECT_HEADERS "${CMAKE_SOURCE_DIR}/src/*.hpp")

# Add your executable and source files
add_executable(2Who ${PROJECT_SOURCES})

# Include GLFW headers
target_include_directories(2Who PRIVATE ${GLFW_INCLUDE_DIR} ${PROJECT_HEADERS})

# Link GLFW and OpenGL
target_link_libraries(2Who PRIVATE ${GLFW_LIBRARY} OpenGL::GL)
