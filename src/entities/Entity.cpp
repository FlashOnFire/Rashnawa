#include <SFML/Graphics/Texture.hpp>
#include "Entity.h"

Entity::Entity(const float x, const float y, const std::string &file_name = "default", const bool has_animation = false) {
    x_ = x;
    y_ = y;
    sprite_.setPosition(x_, y_);
    if (!texture_->loadFromFile("../assets/sprites/" + file_name + ".png")) {
        std::cout << "Can't load " << file_name << ".png, You are so disappointed  :(" << std::endl;
        texture_->loadFromFile("../assets/sprites/default.png");
    }
    sprite_.setTexture(*texture_);
    if (has_animation) {
        animation_ = std::make_unique<Animation>(file_name, [this](const sf::Vector2i coords, const sf::Vector2i size) {
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

void Entity::update(const int delta_time) const {
    if (animation_.has_value()) {
        animation_.value()->update(delta_time);
    }
}

void Entity::set_paused(const bool is_paused) {
    if (animation_.has_value()) {
        animation_.value()->setPaused(is_paused);
    }
}