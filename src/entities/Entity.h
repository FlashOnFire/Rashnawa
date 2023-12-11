#ifndef RASHNAWA_ENTITY_H
#define RASHNAWA_ENTITY_H


#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include <optional>
#include "../graphics/Animations.h"
#include "items/Item.h"
#include "Hitbox.h"

class Entity {
public:
    explicit Entity(std::shared_ptr<sf::Texture> texture);

    explicit Entity(std::shared_ptr<sf::Texture> texture, const std::string &animation_name);

    virtual ~Entity();

    [[nodiscard]] sf::Vector2f getPosition() const;

    void setPosition(float x, float y);

    void setPaused(bool is_paused);

    std::optional<std::weak_ptr<Hitbox>> getHitbox() const;

    void setHitbox(sf::FloatRect new_hitbox);

    std::optional<std::weak_ptr<Animation>> getAnimation() const;

private:
    std::vector<Item> item = std::vector<Item>();
    std::optional<std::shared_ptr<Animation>> animation_;
    std::optional<std::shared_ptr<Hitbox>> hitbox_;
    std::string name_file_;
    std::shared_ptr<sf::Texture> texture_;
    sf::Sprite sprite_;
};


#endif //RASHNAWA_ENTITY_H
