cmake_minimum_required(VERSION 4.0)
project(renderer_lab)

set(CMAKE_CXX_STANDARD 20)


find_package(glm REQUIRED)

add_executable(renderer_lab main.cpp
        math/vector3.cpp
        math/vector3.h
        math/vector2.h
        math/vector2.cpp
        Image.cpp
        Image.h
)

target_link_libraries(renderer_lab PRIVATE glm::glm)