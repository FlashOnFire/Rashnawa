#include "OptionsCategory.h"

const sf::Vector2f &OptionsCategory::getPosition() const {
    return position_;
}

const sf::Vector2f &OptionsCategory::getSize() const {
    return size_;
}

void OptionsCategory::setTransform(const sf::Vector2f &position, const sf::Vector2f &size) {
    position_ = position;
    size_ = size;

    updateComponentsTransform();
}

void OptionsCategory::onMouseMove(const sf::Event::MouseMoveEvent &event) {
    for (const auto &component: components_) {
        component->onMouseMove(event);
    }
}

void OptionsCategory::onMouseButtonPressed(const sf::Event::MouseButtonEvent &event) {
    for (const auto &component: components_) {
        component->onMousePressed(event);
    }
}

void OptionsCategory::onMouseButtonReleased(const sf::Event::MouseButtonEvent &event) {
    for (const auto &component: components_) {
        component->onMouseReleased(event);
    }
}