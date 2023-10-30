cmake_minimum_required(VERSION 3.26)
project(Rashnawa)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/include)
include_directories(./inc)

link_directories(/usr/lib)
link_directories(./lib)

link_libraries(sfml-graphics sfml-window sfml-system fmod fmodstudio)

add_executable(Rashnawa
        src/main.cpp
        src/audio/AudioManager.cpp
        src/audio/EventInstance.cpp
        src/Game.cpp
        src/Game.h
        src/graphics/Renderer.cpp
        src/graphics/Renderer.h
        src/world/World.cpp
        src/world/World.h)
