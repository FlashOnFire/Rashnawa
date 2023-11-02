#include "OptionsCategory.h"

const sf::Vector2f &OptionsCategory::getPosition() const {
    return _position;
}

void OptionsCategory::setPosition(const sf::Vector2f &position) {
    _position = position;
}

const sf::Vector2f &OptionsCategory::getSize() const {
    return _size;
}

void OptionsCategory::setSize(const sf::Vector2f &size) {
    _size = size;
}