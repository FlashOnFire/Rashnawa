#include <SFML/Graphics/Texture.hpp>
#include "Entity.h"

Entity::Entity(float x, float y, const std::string &name_file = "default", bool has_animation = false) {
    x_ = x;
    y_ = y;
    sprite_.setPosition(x_, y_);
    if (!texture_->loadFromFile("../assets/sprites/" + name_file + ".png")) {
        std::cout << "Can't load " << name_file << ".png, You are so disappointed  :(" << std::endl;
        texture_->loadFromFile("../assets/sprites/default/.png");
    }
    sprite_.setTexture(*texture_);
    animation_ = Animation(name_file, [this](const sf::Vector2i coords, const sf::Vector2i size) {
        sprite_.setTextureRect(sf::IntRect(coords, size));
    });
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

void Entity::update(int delta_time) {
    animation_.update(delta_time);
}

void Entity::set_paused() {
    animation_.setPaused(!animation_.paused());
}


