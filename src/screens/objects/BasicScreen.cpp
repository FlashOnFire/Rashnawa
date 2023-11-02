#include <iostream>
#include <utility>
#include "BasicScreen.h"

BasicScreen::BasicScreen(std::shared_ptr<sf::Font> font) : _font(std::move(font)) {
}

BasicScreen::~BasicScreen() = default;
