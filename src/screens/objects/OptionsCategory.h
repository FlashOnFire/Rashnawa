#ifndef RASHNAWA_OPTIONSCATEGORY_H
#define RASHNAWA_OPTIONSCATEGORY_H


#include <memory>
#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>
#include "OptionComponent.h"

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

    virtual void onMouseMove(const sf::Event::MouseMoveEvent &event);
    virtual void onMousePressed(const sf::Event::MouseButtonEvent &event);
    virtual void onMouseReleased(const sf::Event::MouseButtonEvent &event);
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
};


#endif //RASHNAWA_OPTIONSCATEGORY_H
