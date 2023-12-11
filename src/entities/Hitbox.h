#ifndef RASHNAWA_HITBOX_H
#define RASHNAWA_HITBOX_H


#include <SFML/Graphics/Rect.hpp>

class Hitbox {
public:
    Hitbox(float x, float y, float dx, float dy);

    void setHitbox(sf::FloatRect new_hitbox);

    bool isTriggered(sf::Vector2f pos);

    [[nodiscard]] bool isNull() const;

private:
    sf::FloatRect square_;
};


#endif //RASHNAWA_HITBOX_H
