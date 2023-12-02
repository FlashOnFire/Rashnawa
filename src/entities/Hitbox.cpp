
#include "Hitbox.h"

Hitbox::Hitbox(int x, int y, int dx, int dy) {
    square_ = sf::IntRect(x, y, dx, dy);
}
