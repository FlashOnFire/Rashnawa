#include <SFML/Graphics/Texture.hpp>
#include "Entity.h"

Entity::Entity(float x, float y, const std::string &name_file  = "") {
    x_ = x;
    y_ = y;
    sprite_.setTexture(*texture_);
    sprite_.setPosition(x_, y_);
    if (!name_file.empty()) {
        animation_ = Animation(name_file, [this](const sf::Vector2i coords, const sf::Vector2i size) {
            sprite_.setTextureRect(sf::IntRect(coords, size));
        });
    }
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


