
#include "Hitbox.h"

Hitbox::Hitbox(const int x, const int y, const int dx, const int dy) {
    square_ = sf::IntRect(x, y, dx, dy);
}
