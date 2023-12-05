#include "KeybindHandler.h"
#include "Events.h"

#include <utility>
#include <iostream>

KeybindHandler::KeybindHandler(std::shared_ptr<dexode::EventBus> event_bus) : event_bus_(std::move(event_bus)) {
    std::cout << "Created KeybindHandler!" << std::endl;
}

void KeybindHandler::handleEvent(const sf::Event::KeyEvent &event) const {
    for (const auto &[key, value]: keymap_) {
        if (value == event.code) {
            event_bus_->postpone<Events::PlayerAction>({key});
        }
    }
}

