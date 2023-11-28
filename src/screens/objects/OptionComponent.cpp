#include "OptionComponent.h"

const sf::Vector2f &OptionComponent::getPosition() const {
    return _position;
}

const sf::Vector2f &OptionComponent::getSize() const {
    return _size;
}

void OptionComponent::setTransform(const sf::Vector2f &position, const sf::Vector2f &size) {
    _position = position;
    _size = size;

    updateComponentTransform();
}

void OptionComponent::onMouseMove(const sf::Event::MouseMoveEvent &event) {
    // Intentionally blank to allow option components not to implement some events
}

void OptionComponent::onMousePressed(const sf::Event::MouseButtonEvent &event) {
    // Intentionally blank to allow option components not to implement some events
}

void OptionComponent::onMouseReleased(const sf::Event::MouseButtonEvent &event) {
    // Intentionally blank to allow option components not to implement some events
}
