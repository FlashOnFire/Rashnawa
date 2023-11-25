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

    void updateComponentTransform() override;

private:
    std::shared_ptr<sf::Texture> _sliderTexture;
    std::shared_ptr<sf::Texture> _sliderKnobTexture;

    float _scale = 0;

    float _minKnobX = 0;
    float _maxKnobX = 0;

    float _value;
    bool _hovered = false;
    bool _grabbed = false;

    sf::RectangleShape visu;
    sf::RectangleShape _slider;
    sf::RectangleShape _sliderKnob;

    void updateKnobPlacement();

    void onMouseMove(const sf::Event::MouseMoveEvent &event) override;

    void onMousePressed(const sf::Event::MouseButtonEvent &event) override;

    void onMouseReleased(const sf::Event::MouseButtonEvent &event) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //RASHNAWA_SLIDER_H
