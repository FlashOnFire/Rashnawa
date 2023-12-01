#include <utility>
#include "BasicScreen.h"

BasicScreen::BasicScreen(std::shared_ptr<sf::Font> font) : font_(std::move(font)) {
}

void BasicScreen::onMouseMove(const sf::Event::MouseMoveEvent &event) {
    // Intentionally blank to allow screens not to implement some events
}

void BasicScreen::onMousePressed(const sf::Event::MouseButtonEvent &event) {
    // Intentionally blank to allow screens not to implement some events
}

void BasicScreen::onMouseReleased(const sf::Event::MouseButtonEvent &event) {
    // Intentionally blank to allow screens not to implement some events
}

void BasicScreen::onWindowResize(const sf::Event::SizeEvent &event) {
    // Intentionally blank to allow screens not to implement some events
}

BasicScreen::~BasicScreen() = default;
