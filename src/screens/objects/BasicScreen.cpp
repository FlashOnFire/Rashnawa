#include <utility>
#include "BasicScreen.h"

BasicScreen::BasicScreen(std::shared_ptr<dexode::EventBus> event_bus,
                         std::shared_ptr<sf::Font> font) : event_bus_(std::move(event_bus)),
                                                           event_listener_(
                                                               std::make_unique<dexode::EventBus::Listener>(
                                                                   event_bus_)), font_(std::move(font)) {
}

void BasicScreen::onMouseMove(const sf::Event::MouseMoveEvent& event) {
    // Intentionally blank to allow screens not to implement some events
}

void BasicScreen::onMousePressed(const sf::Event::MouseButtonEvent& event) {
    // Intentionally blank to allow screens not to implement some events
}

void BasicScreen::onMouseReleased(const sf::Event::MouseButtonEvent& event) {
    // Intentionally blank to allow screens not to implement some events
}

void BasicScreen::onWindowResize(const sf::Event::SizeEvent& event) {
    // Intentionally blank to allow screens not to implement some events
}

BasicScreen::~BasicScreen() = default;
