
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
    BEDS1,
    BEDS2,
    HUBLOT,
    AFFICHE1, //5
    AFFICHE2,
    PLINTH,
    STUFF1,
    STUFF2,
    STUFF3,  //10
    STUFF4,
    LIGHTS,

    ENTITIES_COUNT
};


#endif //ENTITIES_H
