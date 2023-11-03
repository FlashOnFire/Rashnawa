#include "SoundOptions.h"
#include "objects/Slider.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>

SoundOptions::SoundOptions(std::shared_ptr<sf::Texture> sliderTexture, std::shared_ptr<sf::Texture> sliderKnobTexture)
        : _sliderTexture(std::move(sliderTexture)), _sliderKnobTexture(std::move(sliderKnobTexture)) {
    _components.push_back(std::make_unique<Slider>(_sliderTexture, _sliderKnobTexture));
    _components.push_back(std::make_unique<Slider>(_sliderTexture, _sliderKnobTexture));
}

void SoundOptions::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (const auto &component: _components) {
        target.draw(*component);
    }
}

void SoundOptions::updateComponentsTransform() {
    const auto paddingX = _size.x * 0.1f;
    const auto paddingY = _size.y * 0.1f;
    const auto compSize = sf::Vector2f((_size.x / 2.0f) - (paddingX * 1.5f), 20.0f);

    for (int i = 0; i < _components.size(); i++) {
        _components.at(i)->setTransform(
                sf::Vector2f(
                        _position.x + ((i % 2 == 0) ? paddingX : _size.x / 2.0f + paddingX * 0.5f),
                        _position.y + paddingY),
                compSize);
    }
}
