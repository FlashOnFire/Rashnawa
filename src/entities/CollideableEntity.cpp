#include "CollideableEntity.h"

const Hitbox &CollideableEntity::getHitbox() const {
    return _hitbox;
}

void CollideableEntity::setHitbox(const Hitbox &hitbox) {
    _hitbox = hitbox;
}
