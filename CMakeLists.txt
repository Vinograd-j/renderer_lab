cmake_minimum_required(VERSION 4.0)
project(renderer_lab)

set(CMAKE_CXX_STANDARD 20)


find_package(glm REQUIRED)

add_executable(renderer_lab main.cpp
        math/src/vector3.cpp
        math/include/vector3.h
        math/include/vector2.h
        math/src/vector2.cpp
        Image.cpp
        Image.h
        shapes/src/circle.cpp
        shapes/include/circle.h
        shapes/include/drawable.h
        material/gradient-colors/include/color-provider.h
        material/gradient-colors/include/solid-color.h
        material/gradient-colors/include/gradient-color.h
        material/gradient-colors/src/vertical-gradient.cpp
        material/gradient-colors/include/vertical-gradient.h
        material/gradient-colors/src/horizontal-gradient.cpp
        material/gradient-colors/include/horizontal-gradient.h
        shapes/src/background.cpp
        shapes/include/background.h
        material/gradient-colors/src/radial-gradient.cpp
        material/gradient-colors/include/radial-gradient.h
        shapes/src/line-dda.cpp
        shapes/include/line-dda.h
        renderer/src/renderer.cpp
        renderer/include/renderer.h
        shapes/src/triangle.cpp
        shapes/include/triangle.h
        renderer/include/Context.h
        shapes/include/Vertex.h
)

target_link_libraries(renderer_lab PRIVATE glm::glm)