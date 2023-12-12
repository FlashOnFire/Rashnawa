#include "PauseMenuScreen.h"

#include "../events/Events.h"

PauseMenuScreen::PauseMenuScreen(std::shared_ptr<dexode::EventBus> event_bus,
                                 std::shared_ptr<sf::Font> font) : BasicScreen(std::move(event_bus), std::move(font)) {
    event_listener_->listen<Events::EscapeBtn>([this](const Events::EscapeBtn &) {
        event_bus_->postpone<Events::ChangeScreen>({.from = Screens::PauseMenu, .to = Screens::None});
    });
}

void PauseMenuScreen::render(std::shared_ptr<sf::RenderWindow> window) const {
    // Not implemented yet
}
