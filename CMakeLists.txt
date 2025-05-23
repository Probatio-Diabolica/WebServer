cmake_minimum_required(VERSION 3.28)
project(WebServer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-O3 -march=native -Wall -Wextra)

file(GLOB_RECURSE SOURCE_FILES
    src/*.cpp
)

add_executable(webserver ${SOURCE_FILES})

target_include_directories(webserver PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Server
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Server/Sockets
)
