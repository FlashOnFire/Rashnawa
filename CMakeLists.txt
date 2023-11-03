cmake_minimum_required(VERSION 3.26)
project(Rashnawa)

set(CMAKE_CXX_STANDARD 20)

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
        src/screens/objects/BasicScreen.cpp
        src/screens/objects/BasicScreen.h
        src/screens/MainMenuScreen.cpp
        src/screens/MainMenuScreen.h
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
        src/events/Events.h
        inc/dexode/EventBus.cpp
        src/screens/OptionsMenuScreen.cpp
        src/screens/OptionsMenuScreen.h
        src/audio/MusicManager.cpp
        src/audio/MusicManager.h
        src/events/EventManager.cpp
        src/events/EventManager.h
        src/screens/Screens.h
        src/screens/OptionsCategories.h
        src/screens/objects/Slider.cpp
        src/screens/objects/Slider.h
        src/screens/objects/OptionsCategory.cpp
        src/screens/objects/OptionsCategory.h
        src/screens/objects/OptionComponent.cpp
        src/screens/objects/OptionComponent.h
        src/screens/SoundOptions.cpp
        src/screens/SoundOptions.h
        src/screens/objects/TextButton.cpp
        src/screens/objects/TextButton.h
)
