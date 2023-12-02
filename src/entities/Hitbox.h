#ifndef RASHNAWA_HITBOX_H
#define RASHNAWA_HITBOX_H


#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

class Hitbox {
public:
    Hitbox(int x, int y, int dx, int dy);
private:
    sf::IntRect square_;
};


#endif //RASHNAWA_HITBOX_H
