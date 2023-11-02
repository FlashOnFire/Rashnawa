#ifndef RASHNAWA_OPTIONCOMPONENT_H
#define RASHNAWA_OPTIONCOMPONENT_H


#include <SFML/Graphics/Drawable.hpp>

class OptionComponent : public sf::Drawable {
public:
    ~OptionComponent() override;
    [[nodiscard]] virtual const sf::Vector2f &getPosition() const = 0;

    virtual void setPosition(const sf::Vector2f &position) = 0;

    [[nodiscard]] virtual const sf::Vector2f &getSize() const = 0;

    virtual void setSize(const sf::Vector2f &size) = 0;
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
};


#endif //RASHNAWA_OPTIONCOMPONENT_H
