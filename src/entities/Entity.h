#ifndef RASHNAWA_ENTITY_H
#define RASHNAWA_ENTITY_H


#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include "../graphics/Animations.h"
#include "items/Item.h"

class Entity {
private:
    float x_;
    float y_;
    std::vector<Item> item = std::vector<Item> ();
    Animation animation_;
    std::string name_file_;
    std::unique_ptr<sf::Texture> texture_;
    sf::Sprite sprite_;
public:
    Entity(float x, float y, const std::string &name_file);

    virtual ~Entity();

    [[nodiscard]] float getX() const;

    void setX(float x);

    [[nodiscard]] float getY() const;

    void setY(float y);
};


#endif //RASHNAWA_ENTITY_H
