
#include "Hitbox.h"

Hitbox::Hitbox(int x, int y, int dx, int dy) {
    _square = sf::IntRect(x, y, dx, dy);
}
