cmake_minimum_required(VERSION 3.14)
project(Voxel4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
include_directories("Include")
add_executable(Voxel4 main.cpp Res/glad.c Engine/WindowManager.h Engine/Mesh.cpp Engine/Mesh.h Engine/MeshHandler.cpp Engine/MeshHandler.h Engine/Renderer.cpp Engine/Renderer.h Engine/Shader.cpp Engine/Shader.h Engine/World.cpp Engine/World.h Engine/Actor.cpp Engine/Actor.h Engine/Object3d.cpp Engine/Object3d.h Engine/Transform.cpp Engine/Transform.h Engine/Camera.cpp Engine/Camera.h)

target_link_libraries(Voxel4 -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl)