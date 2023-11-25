#include <utility>
#include "BasicScreen.h"

BasicScreen::BasicScreen(std::shared_ptr<sf::Font> font) : _font(std::move(font)) {
}

void BasicScreen::onMouseMove(const sf::Event::MouseMoveEvent &event) {
}

void BasicScreen::onMousePressed(const sf::Event::MouseButtonEvent &event) {
}

void BasicScreen::onMouseReleased(const sf::Event::MouseButtonEvent &event) {
}

void BasicScreen::onWindowResize(const sf::Event::SizeEvent &event) {
}

BasicScreen::~BasicScreen() = default;
