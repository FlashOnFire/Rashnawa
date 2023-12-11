
#include "Hitbox.h"

Hitbox::Hitbox(const float x, const float y, const float dx, const float dy) {
    square_ = sf::FloatRect(x, y, dx, dy);
}

void Hitbox::setHitbox(const sf::FloatRect new_hitbox) {
    square_ = new_hitbox;
}

bool Hitbox::isTriggered(sf::Vector2f pos) {
    if (square_.contains(pos)) {
        return true;
    }
    return false;
}
