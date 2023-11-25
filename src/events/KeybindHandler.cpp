#include "KeybindHandler.h"
#include "Events.h"

#include <utility>
#include <iostream>

KeybindHandler::KeybindHandler(std::shared_ptr<dexode::EventBus> eventBus) : _eventBus(std::move(eventBus)) {
    std::cout << "Created KeybindHandler!" << std::endl;
}

void KeybindHandler::handleEvent(const sf::Event::KeyEvent &event) {
    for (const auto &[key, value]: _keymap) {
        if (value == event.code) {
            _eventBus->postpone<Events::PlayerAction>({key});
        }
    }
}

