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
