#include "CollideableEntity.h"

const Hitbox &CollideableEntity::getHitbox() const {
    return hitbox_;
}

void CollideableEntity::setHitbox(const Hitbox &hitbox) {
    hitbox_ = hitbox;
}
