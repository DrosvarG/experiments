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

find_package(Catch2 REQUIRED)

#=============================================================================

add_library(myarray STATIC 
    src/myarray/myarray.h 
    src/myarray/myarray.tpp  
)
target_include_directories(myarray PUBLIC src)
set_target_properties(myarray PROPERTIES LINKER_LANGUAGE CXX)

add_executable(vector src/main.cpp)
target_link_libraries(vector PRIVATE myarray)

#=============================================================================

add_executable(runtests 
    tests/myarray/myarray.cpp
)
target_link_libraries(runtests PRIVATE Catch2::Catch2WithMain myarray)
add_test(NAME runtests COMMAND runtests)