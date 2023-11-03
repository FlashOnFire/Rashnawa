#include "Slider.h"

#include <utility>
#include <cmath>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <iostream>

Slider::Slider(std::shared_ptr<sf::Texture> sliderTexture, std::shared_ptr<sf::Texture> sliderKnobTexture,
               float value) : _sliderTexture(std::move(sliderTexture)),
                              _sliderKnobTexture(std::move(sliderKnobTexture)), _value(value) {

    _slider.setTexture(_sliderTexture.get());
    _slider.setSize(sf::Vector2f(_sliderTexture->getSize()));
    _sliderKnob.setTexture(_sliderKnobTexture.get());
    _sliderKnob.setSize(sf::Vector2f(_sliderKnobTexture->getSize()));

    visu.setFillColor(sf::Color(30, 30, 30, 180));
    std::cout << "Created Slider!" << std::endl;
}

float Slider::getValue() const {
    return _value;
}

void Slider::setValue(const float value) {
    _value = value;
}

void Slider::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(visu);
    target.draw(_slider);
    target.draw(_sliderKnob);
}

void Slider::updateComponentTransform() {
    const auto paddingX = _size.x * 0.1f;

    _scale = (_size.x - 2.0f * paddingX) / (float) _sliderTexture->getSize().x;

    std::cout << "padding : " << paddingX << std::endl;
    std::cout << "scale : " << _scale << std::endl;

    _slider.setScale(_scale, _scale);

    _slider.setPosition(sf::Vector2f(_position.x + paddingX, _position.y + _size.y * 0.5f -
                                                             (float) _sliderTexture->getSize().y * _scale * 0.5f));

    visu.setPosition(_position);
    visu.setSize(_size);

    _sliderKnob.setScale(_scale, _scale);

    _minKnobX = _slider.getPosition().x - (_sliderKnob.getSize().x * _scale * 0.5f);
    _maxKnobX =
            _slider.getPosition().x + (_slider.getSize().x * _scale) - (_sliderKnob.getSize().x * _scale * 0.5f);

    updateKnobPlacement();
}

void Slider::updateKnobPlacement() {
    const auto posX = std::lerp(_minKnobX, _maxKnobX, _value);
    const auto posY =
            _slider.getPosition().y + _slider.getSize().y * _scale * 0.5f - _sliderKnob.getSize().y * _scale * 0.5f;

    _sliderKnob.setPosition(posX, posY);
}

void Slider::onMouseMove(const sf::Event::MouseMoveEvent &e) {
    _hovered = (float) e.x > _sliderKnob.getPosition().x &&
               (float) e.x < (_sliderKnob.getPosition().x + (_sliderKnob.getSize().x) * _scale)
               && (float) e.y > _sliderKnob.getPosition().y &&
               (float) e.y < (_sliderKnob.getPosition().y + (_sliderKnob.getSize().y) * _scale);

    if (_grabbed) {
        const float invLerp = (((float) e.x - _sliderKnob.getSize().x * _scale * 0.5f) - _minKnobX) / (_maxKnobX - _minKnobX);

        _value = std::clamp(invLerp , 0.0f, 1.0f);
        updateKnobPlacement();
    }
}

void Slider::onMousePressed(const sf::Event::MouseButtonEvent &event) {
    if (_hovered) {
        _grabbed = true;
    }
}

void Slider::onMouseReleased(const sf::Event::MouseButtonEvent &event) {
    if (_grabbed)
        _grabbed = false;
}