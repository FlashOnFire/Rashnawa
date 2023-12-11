
#ifndef ENTITIES_H
#define ENTITIES_H


#include <string>
#include <vector>
#include "SFML/Graphics/Rect.hpp"
#include "patterns/Pattern.h"
#include "Hitbox.h"

struct EntityPrototype {
    std::string name = "default";
    bool has_animation = false;
    Hitbox coord_hitbox = Hitbox(0.0f, 0.0f, 0.0f, 0.0f);
    std::vector<Pattern> patterns;
    bool has_IA = false;
    // we will add some useful stuff soon ^^
};

enum class Entities {
    GROUND = 0,
    PLAYER,
    Monster1,

    ENTITIES_COUNT
};


#endif //ENTITIES_H
