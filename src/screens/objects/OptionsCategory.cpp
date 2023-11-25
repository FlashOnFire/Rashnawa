#include "OptionsCategory.h"

const sf::Vector2f &OptionsCategory::getPosition() const {
    return _position;
}

const sf::Vector2f &OptionsCategory::getSize() const {
    return _size;
}

void OptionsCategory::setTransform(const sf::Vector2f &position, const sf::Vector2f &size) {
    _position = position;
    _size = size;

    updateComponentsTransform();
}

void OptionsCategory::onMouseMove(const sf::Event::MouseMoveEvent &event) {
    for (const auto &component: _components) {
        component->onMouseMove(event);
    }
}

void OptionsCategory::onMouseButtonPressed(const sf::Event::MouseButtonEvent &event) {
    for (const auto &component: _components) {
        component->onMousePressed(event);
    }
}

void OptionsCategory::onMouseButtonReleased(const sf::Event::MouseButtonEvent &event) {
    for (const auto &component: _components) {
        component->onMouseReleased(event);
    }
}