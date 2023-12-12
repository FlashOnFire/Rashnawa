#ifndef OPTIONDATASTRUCTS_H
#define OPTIONDATASTRUCTS_H


#include <variant>

struct SoundOptionData {
    float master_volume = 1;
    float music_volume = 1;
    float effects_volume = 1;
};

enum class SoundOptionType {
    MASTER_VOLUME,
    MUSIC_VOLUME,
    EFFECTS_VOLUME,
};

struct GraphicsOptionsData {
    int fps = 240;
};

enum class GraphicsOptionType {
    FPS,
};

struct OptionsSnapshot {
    SoundOptionData sound;
    GraphicsOptionsData graphics;
};

using GenericOption = std::variant<int, float, bool>;


#endif //OPTIONDATASTRUCTS_H
