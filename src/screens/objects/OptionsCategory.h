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

    [[nodiscard]] const sf::Vector2f &getPosition() const;

    [[nodiscard]] const sf::Vector2f &getSize() const;

    void setTransform(const sf::Vector2f &position, const sf::Vector2f &size);

    virtual void updateComponentsTransform() = 0;

    virtual void onMouseMove(const sf::Event::MouseMoveEvent &event);

    virtual void onMouseButtonPressed(const sf::Event::MouseButtonEvent &event);

    virtual void onMouseButtonReleased(const sf::Event::MouseButtonEvent &event);

protected:
    sf::Vector2f position_;
    sf::Vector2f size_;

    std::vector<std::unique_ptr<OptionComponent>> components_;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override = 0;
};


#endif //RASHNAWA_OPTIONSCATEGORY_H
