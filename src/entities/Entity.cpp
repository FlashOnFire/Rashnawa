#include <SFML/Graphics/Texture.hpp>
#include "Entity.h"

Entity::Entity(const std::string &file_name, bool has_animation) {
    if (!texture_->loadFromFile("../assets/sprites/" + file_name + ".png")) {
        std::cout << "Can't load " << file_name << ".png, You are so disappointed  :(" << std::endl;
        texture_->loadFromFile("../assets/sprites/default.png");
    }
    sprite_.setTexture(*texture_);

    if (has_animation) {
        animation_ = std::make_shared<Animation>(file_name,
                                                 [this](const sf::Vector2i coords, const sf::Vector2i size) {
                                                     sprite_.setTextureRect(sf::IntRect(coords, size));
                                                 });
    }
}

Entity::~Entity() = default;

sf::Vector2f Entity::getPosition() const {
    return sprite_.getPosition();
}

void Entity::setPosition(const float x, const float y) {
    sprite_.setPosition(x, y);
}

void Entity::setPaused(const bool is_paused) {
    if (animation_.has_value()) {
        animation_.value()->setPaused(is_paused);
    }
}

std::optional<std::weak_ptr<Animation>> Entity::getAnimation() const {
    return animation_;
}
