cmake_minimum_required(VERSION 3.28)
project(hellopengl LANGUAGES CXX)

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
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

#=============================================================================

#add_library(myarray STATIC)
#target_include_directories(myarray PUBLIC src)
#set_target_properties(myarray PROPERTIES LINKER_LANGUAGE CXX)

add_executable(hellopengl src/main.cpp)

target_link_libraries(hellopengl PRIVATE glfw)
target_link_libraries(hellopengl PRIVATE OpenGL::GL)

#=============================================================================

#add_executable(runtests)
#target_link_libraries(runtests PRIVATE Catch2::Catch2WithMain)
#add_test(NAME runtests COMMAND runtests)
