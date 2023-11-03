#ifndef RASHNAWA_OPTIONSCATEGORY_H
#define RASHNAWA_OPTIONSCATEGORY_H


#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include "OptionComponent.h"
#include <memory>

class OptionsCategory : public sf::Drawable {
public:
    OptionsCategory() = default;
    ~OptionsCategory() override = default;
protected:
    sf::Vector2f _position;
    sf::Vector2f _size;

    std::vector<std::unique_ptr<OptionComponent>> _components;
public:
    [[nodiscard]] const sf::Vector2f &getPosition() const;

    [[nodiscard]] const sf::Vector2f &getSize() const;

    void setTransform(const sf::Vector2f &position, const sf::Vector2f &size);

    virtual void updateComponentsTransform() = 0;
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
};


#endif //RASHNAWA_OPTIONSCATEGORY_H
