#ifndef RASHNAWA_ENTITY_H
#define RASHNAWA_ENTITY_H


#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include <optional>
#include "../graphics/Animations.h"
#include "items/Item.h"

class Entity {
public:
    Entity(float x, float y, const std::string& file_name, bool has_animation);

    virtual ~Entity();

    [[nodiscard]] float getX() const;

    void setX(float x);

    [[nodiscard]] float getY() const;

    void setY(float y);

    void update(int delta_time) const;

    void set_paused(bool is_paused);

private:
    float x_;
    float y_;
    std::vector<Item> item = std::vector<Item>();
    std::optional<std::unique_ptr<Animation>> animation_;
    std::string name_file_;
    std::unique_ptr<sf::Texture> texture_;
    sf::Sprite sprite_;
};


#endif //RASHNAWA_ENTITY_H
