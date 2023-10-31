#include "Entity.h"

Entity::Entity(const float x, const float y) {
    _x = x;
    _y = y;
}

Entity::~Entity() = default;

float Entity::getX() const {
    return _x;
}

void Entity::setX(float x) {
    _x = x;
}

float Entity::getY() const {
    return _y;
}

void Entity::setY(float y) {
    _y = y;
}