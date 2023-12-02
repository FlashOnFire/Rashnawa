#include "Slider.h"

#include <utility>
#include <cmath>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

Slider::Slider(std::shared_ptr<sf::Texture> sliderTexture, std::shared_ptr<sf::Texture> slider_knob_texture,
               std::function<void(float value)> callback,
               const float value) : slider_texture_(std::move(sliderTexture)),
                                    slider_knob_slider_knob_texture_(std::move(slider_knob_texture)), value_(value),
                                    callback_(std::move(callback)) {
    slider_.setTexture(slider_texture_.get());
    slider_.setSize(sf::Vector2f(slider_texture_->getSize()));
    slider_knob_.setTexture(slider_knob_slider_knob_texture_.get());
    slider_knob_.setSize(sf::Vector2f(slider_knob_slider_knob_texture_->getSize()));

    visu_.setFillColor(sf::Color(30, 30, 30, 180));
}

float Slider::getValue() const {
    return value_;
}

void Slider::setValue(const float value) {
    value_ = value;
}

void Slider::updateComponentTransform() {
    const auto paddingX = size_.x * 0.1f;

    scale_ = (size_.x - 2.0f * paddingX) / static_cast<float>(slider_texture_->getSize().x);

    slider_.setScale(scale_, scale_);

    slider_.setPosition(sf::Vector2f(position_.x + paddingX, position_.y + size_.y * 0.5f -
                                                             static_cast<float>(slider_texture_->getSize().y)
                                                             * scale_ * 0.5f));

    visu_.setPosition(position_);
    visu_.setSize(size_);

    slider_knob_.setScale(scale_, scale_);

    min_knob_x_ = slider_.getPosition().x - (slider_knob_.getSize().x * scale_ * 0.5f);
    max_knob_x_ =
            slider_.getPosition().x + (slider_.getSize().x * scale_) - (slider_knob_.getSize().x * scale_ * 0.5f);

    slider_knob_.setPosition(0,
                             slider_.getPosition().y + slider_.getSize().y * scale_ * 0.5f -
                             slider_knob_.getSize().y * scale_ * 0.5f);

    updateKnobPlacement();
}

void Slider::updateKnobPlacement() {
    const auto posX = std::lerp(min_knob_x_, max_knob_x_, value_);
    slider_knob_.setPosition(posX, slider_knob_.getPosition().y);
}

void Slider::onMouseMove(const sf::Event::MouseMoveEvent& event) {
    hovered_ = static_cast<float>(event.x) > slider_knob_.getPosition().x &&
               static_cast<float>(event.x) < (slider_knob_.getPosition().x + (slider_knob_.getSize().x) * scale_)
               && static_cast<float>(event.y) > slider_knob_.getPosition().y &&
               static_cast<float>(event.y) < (slider_knob_.getPosition().y + (slider_knob_.getSize().y) * scale_);

    if (grabbed_) {
        const float invLerp =
                ((static_cast<float>(event.x) - slider_knob_.getSize().x * scale_ * 0.5f) - min_knob_x_)
                / (max_knob_x_ - min_knob_x_);

        value_ = std::round(std::clamp(invLerp, 0.0f, 1.0f) * 100.0f) / 100.0f;
        updateKnobPlacement();

        callback_(value_);
    }
}

void Slider::onMousePressed(const sf::Event::MouseButtonEvent& event) {
    if (hovered_) {
        grabbed_ = true;
    }
}

void Slider::onMouseReleased(const sf::Event::MouseButtonEvent& event) {
    if (grabbed_)
        grabbed_ = false;
}

void Slider::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(visu_);
    target.draw(slider_);
    target.draw(slider_knob_);
}
