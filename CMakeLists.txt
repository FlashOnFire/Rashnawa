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
        src/world/World.h
        src/screens/BasicScreen.cpp
        src/screens/BasicScreen.h
        src/screens/MainMenu.cpp
        src/screens/MainMenu.h
        src/screens/objects/Button.cpp
        src/screens/objects/Button.h
        src/entities/Entity.cpp
        src/entities/Entity.h
        src/entities/CollideableEntity.cpp
        src/entities/CollideableEntity.h
        src/entities/Hitbox.cpp
        src/entities/Hitbox.h
        src/entities/BlockEntity.cpp
        src/entities/BlockEntity.h
        src/entities/LivingEntity.cpp
        src/entities/LivingEntity.h
        src/entities/Pnj.cpp
        src/entities/Pnj.h
        src/entities/Player.cpp
        src/entities/Player.h
        src/entities/weapons/Weapon.h
        src/events/Events.hpp
        inc/dexode/EventBus.cpp
)
