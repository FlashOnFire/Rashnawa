#include "Slider.h"

#include <utility>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <iostream>

Slider::Slider(std::shared_ptr<sf::Texture> sliderTexture, std::shared_ptr<sf::Texture> sliderKnobTexture,
               float value) : _sliderTexture(std::move(sliderTexture)),
                              _sliderKnobTexture(std::move(sliderKnobTexture)), _value(value) {

    _slider.setTexture(_sliderTexture.get());
    _sliderKnob.setTexture(*_sliderKnobTexture);
    std::cout << "Created Slider!" << std::endl;
}

float Slider::getValue() const {
    return _value;
}

void Slider::setValue(const float value) {
    _value = value;
}

void Slider::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(_slider);
    target.draw(_sliderKnob);
    //std::cout << "draw slider" << std::endl;
}

const sf::Vector2f &Slider::getPosition() const {
    return _slider.getPosition();
}

const sf::Vector2f &Slider::getSize() const {
    return _slider.getSize();
}

void Slider::setTransform(const sf::Vector2f &position, const sf::Vector2f &size) {
    _slider.setPosition(position);
    _slider.setSize(size);
}