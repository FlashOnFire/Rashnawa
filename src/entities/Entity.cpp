#include "Entity.h"

Entity::Entity(const float x, const float y) : x_(x), y_(y) {
}

Entity::~Entity() = default;

float Entity::getX() const {
    return x_;
}

void Entity::setX(const float x) {
    x_ = x;
}

float Entity::getY() const {
    return y_;
}

void Entity::setY(const float y) {
    y_ = y;
}
