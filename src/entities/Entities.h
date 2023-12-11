
#ifndef ENTITIES_H
#define ENTITIES_H


#include <string>
#include "SFML/Graphics/Rect.hpp"

struct EntityPrototype {
    std::string name = "default";
    bool has_animation = false;
    sf::FloatRect coord_hitbox = sf::FloatRect(0.0f, 0.0f, 0.0f, 0.0f);
    bool has_patterns = false;
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
