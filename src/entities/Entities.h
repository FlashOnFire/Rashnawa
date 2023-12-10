
#ifndef ENTITIES_H
#define ENTITIES_H


#include <string>

struct EntityPrototype {
    std::string name = "default";
    bool has_animation = false;
};

enum class Entities {
    GROUND = 0,
    PLAYER,
    Monster1,

    ENTITIES_COUNT
};


#endif //ENTITIES_H
