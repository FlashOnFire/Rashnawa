cmake_minimum_required(VERSION 3.26)
project(Rashnawa)

set(CMAKE_CXX_STANDARD 20)

include_directories(./inc)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    link_directories(lib_windows)
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -mwindows")

    cmake_path(GET CMAKE_CXX_COMPILER PARENT_PATH PARENT_DIR)
    file(GLOB WINDOWS_DLLS
            "lib_windows/*.dll"
            "${PARENT_DIR}/*.dll"
    )

    message("${WINDOWS_DLLS}")
    message("dfgfd")
    file( COPY ${WINDOWS_DLLS} DESTINATION "${cmake-build-debug}/" )
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    include_directories(/usr/include)
    link_directories(lib_linux)
    set(CMAKE_BUILD_RPATH "lib_linux:../lib_linux:.")
endif ()

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
        src/events/KeybindHandler.cpp
        src/events/KeybindHandler.h
        src/events/Keybinds.h
        src/world/Room.cpp
        src/world/Room.h
        src/screens/objects/ButtonBuilder.cpp
        src/screens/objects/ButtonBuilder.h
        src/graphics/Animations.h
        src/graphics/Animations.cpp
        src/storage/OptionsManager.h
        src/storage/OptionsManager.cpp
        src/storage/options/OptionDataStructs.h
        src/entities/items/Item.cpp
        src/screens/PauseMenuScreen.cpp
        src/screens/PauseMenuScreen.h
)
