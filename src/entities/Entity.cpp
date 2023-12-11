#include <SFML/Graphics/Texture.hpp>
#include "Entity.h"

Entity::Entity(std::shared_ptr<sf::Texture> texture) : texture_(std::move(texture)) {
    sprite_.setTexture(*texture_);
}

Entity::Entity(std::shared_ptr<sf::Texture> texture, const std::string &animation_name) : Entity(std::move(texture)) {
    animation_ = std::make_shared<Animation>(animation_name,
                                             [this](const sf::Vector2i coords, const sf::Vector2i size) {
                                                 sprite_.setTextureRect(sf::IntRect(coords, size));
                                             });
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

std::optional<std::shared_ptr<std::vector<Pattern>>> Entity::getPatterns() const{
    return pattern_;
}

void Entity::setPatterns(const std::vector<Pattern> &patterns) {
    if (pattern_.has_value()) {
        pattern_.reset();
    } else {
        pattern_ = std::make_shared<std::vector<Pattern>>();
    }
    for (auto pattern: patterns) {
        pattern_.value()->push_back(pattern);
    }
}

std::optional<std::weak_ptr<Hitbox>> Entity::getHitbox() const {
    return hitbox_;
}

void Entity::setHitbox(const Hitbox& new_hitbox) {
    hitbox_.value() = std::make_shared<Hitbox>(new_hitbox);
}

std::optional<std::weak_ptr<Animation>> Entity::getAnimation() const {
    return animation_;
}

