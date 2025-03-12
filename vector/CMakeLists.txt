cmake_minimum_required(VERSION 3.28)
project(vector LANGUAGES CXX)

enable_testing()

#=============================================================================

add_compile_options(
    -Wall -Wextra
    -Wcast-align -Wcast-qual -Wold-style-cast
    -Wconversion -Wshadow -Wstrict-overflow=3
)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

#=============================================================================

add_library(myarray STATIC 
    src/myarray/myarray.cpp
    src/myarray/myarray.h    
)
target_include_directories(myarray PUBLIC src)

add_executable(vector src/main.cpp)
target_link_libraries(vector PRIVATE myarray)

#=============================================================================

