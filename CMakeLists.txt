cmake_minimum_required(VERSION 3.26)
project(Rashnawa)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/include)
include_directories(./inc)

link_directories(/usr/lib)
link_directories(./lib)

link_libraries(sfml-graphics sfml-window sfml-system fmod fmodstudio)

add_executable(Rashnawa

        main.cpp
        audio/AudioManager.cpp
        audio/EventInstance.cpp)
