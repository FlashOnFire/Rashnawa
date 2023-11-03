#ifndef RASHNAWA_OPTIONCOMPONENT_H
#define RASHNAWA_OPTIONCOMPONENT_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>

class OptionComponent : public sf::Drawable {
public:
    ~OptionComponent() override = default;

    [[nodiscard]] const sf::Vector2f &getPosition() const;

    [[nodiscard]] const sf::Vector2f &getSize() const;

    virtual void setTransform(const sf::Vector2f &position, const sf::Vector2f &size);

    virtual void updateComponentTransform() = 0;

    virtual void onMouseMove(const sf::Event::MouseMoveEvent &event);
    virtual void onMousePressed(const sf::Event::MouseButtonEvent &event);
    virtual void onMouseReleased(const sf::Event::MouseButtonEvent &event);
protected:
    sf::Vector2f _position, _size;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
};


#endif //RASHNAWA_OPTIONCOMPONENT_H
