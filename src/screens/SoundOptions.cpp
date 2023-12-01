#include "SoundOptions.h"
#include "objects/Slider.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>

SoundOptions::SoundOptions(std::shared_ptr<sf::Texture> sliderTexture, std::shared_ptr<sf::Texture> sliderKnobTexture)
        : _sliderTexture(std::move(sliderTexture)), _sliderKnobTexture(std::move(sliderKnobTexture)) {
    _components.push_back(std::make_unique<Slider>(_sliderTexture, _sliderKnobTexture, [](const float value){
            std::cout << "value: " << value<< std::endl;
        }, 1));
    _components.push_back(std::make_unique<Slider>(_sliderTexture, _sliderKnobTexture, [](const float value){
        std::cout << "value: " << value<< std::endl;
    },  0.25));
    _components.push_back(std::make_unique<Slider>(_sliderTexture, _sliderKnobTexture, [](const float value){
        std::cout << "value: " << value<< std::endl;
    }, 0.5));
    _components.push_back(std::make_unique<Slider>(_sliderTexture, _sliderKnobTexture, [](const float value){
        std::cout << "value: " << value<< std::endl;
    }, 1));
}

void SoundOptions::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (const auto &component: _components) {
        target.draw(*component);
    }
}

void SoundOptions::updateComponentsTransform() {
    const auto paddingX = _size.x * 0.1f;
    const auto paddingY = _size.y * 0.1f;

    const auto paddingYBetweenComp = (_size.y - 2 * paddingY) * 0.05f;

    const auto compSize = sf::Vector2f((_size.x / 2.0f) - (paddingX * 1.5f), ((_size.y - 2 * paddingY) * 0.15f));

    for (int i = 0; i < _components.size(); i++) {
        _components.at(i)->setTransform(
                sf::Vector2f(
                        _position.x + ((i % 2 == 0) ? paddingX : _size.x / 2.0f + paddingX * 0.5f),
                        _position.y + paddingY + (compSize.y + paddingYBetweenComp) * ((float) (i / 2))),
                compSize);
    }
}
