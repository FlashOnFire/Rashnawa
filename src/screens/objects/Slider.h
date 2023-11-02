#ifndef RASHNAWA_SLIDER_H
#define RASHNAWA_SLIDER_H

#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "OptionComponent.h"

class Slider : public OptionComponent {
public:
    Slider() = delete;
    Slider(std::shared_ptr<sf::Texture> sliderTexture, std::shared_ptr<sf::Texture> sliderKnobTexture, float value = 0);

    [[nodiscard]] float getValue() const;

    void setValue(float value);

    [[nodiscard]] const sf::Vector2f &getPosition() const override;

    void setPosition(const sf::Vector2f &position) override;

    [[nodiscard]] const sf::Vector2f &getSize() const override;

    void setSize(const sf::Vector2f &size) override;

private:
    std::shared_ptr<sf::Texture> _sliderTexture;
    std::shared_ptr<sf::Texture> _sliderKnobTexture;

    float _value;
    sf::RectangleShape _slider;
    sf::Sprite _sliderKnob;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};



#endif //RASHNAWA_SLIDER_H
