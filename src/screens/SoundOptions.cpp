#include "SoundOptions.h"
#include "objects/Slider.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>

SoundOptions::SoundOptions(std::shared_ptr<sf::Texture> slider_texture,
                           std::shared_ptr<sf::Texture> slider_knob_texture)
    : slider_texture_(std::move(slider_texture)), slider_knob_texture_(std::move(slider_knob_texture)) {
    components_.push_back(std::make_unique<Slider>(slider_texture_, slider_knob_texture_, [](const float value) {
        std::cout << "value: " << value << std::endl;
    }, 1));
    components_.push_back(std::make_unique<Slider>(slider_texture_, slider_knob_texture_, [](const float value) {
        std::cout << "value: " << value << std::endl;
    }, 0.25));
    components_.push_back(std::make_unique<Slider>(slider_texture_, slider_knob_texture_, [](const float value) {
        std::cout << "value: " << value << std::endl;
    }, 0.5));
    components_.push_back(std::make_unique<Slider>(slider_texture_, slider_knob_texture_, [](const float value) {
        std::cout << "value: " << value << std::endl;
    }, 1));
}

void SoundOptions::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto& component: components_) {
        target.draw(*component);
    }
}

void SoundOptions::updateComponentsTransform() {
    const auto padding_x = size_.x * 0.1f;
    const auto padding_y = size_.y * 0.1f;

    const auto paddingYBetweenComp = (size_.y - 2 * padding_y) * 0.05f;

    const auto compSize = sf::Vector2f((size_.x / 2.0f) - (padding_x * 1.5f), ((size_.y - 2 * padding_y) * 0.15f));

    for (int i = 0; i < components_.size(); i++) {
        components_.at(i)->setTransform(
            sf::Vector2f(
                position_.x + ((i % 2 == 0) ? padding_x : size_.x / 2.0f + padding_x * 0.5f),
                position_.y + padding_y + (compSize.y + paddingYBetweenComp) * static_cast<float>(i) / 2),
            compSize);
    }
}
