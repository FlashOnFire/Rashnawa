
#ifndef ENTITIES_H
#define ENTITIES_H


#include <string>
#include <vector>
#include <optional>
#include "SFML/Graphics/Rect.hpp"
#include "patterns/Pattern.h"
#include "Hitbox.h"

struct EntityPrototype {
    std::string name = "default";
    bool has_animation = false;
    std::optional<Hitbox> hitbox;
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
