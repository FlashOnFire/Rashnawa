#ifndef OPTIONDATASTRUCTS_H
#define OPTIONDATASTRUCTS_H


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

union GenericOption {
    float _float;
    int _int;
    bool _bool;
};


#endif //OPTIONDATASTRUCTS_H
