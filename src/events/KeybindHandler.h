#ifndef RASHNAWA_KEYBINDHANDLER_H
#define RASHNAWA_KEYBINDHANDLER_H


#include <memory>
#include <SFML/Window/Event.hpp>
#include "dexode/EventBus.hpp"
#include "Keybinds.h"

class KeybindHandler {
public:
    explicit KeybindHandler(std::shared_ptr<dexode::EventBus> event_bus);

    void handleEvent(const sf::Event::KeyEvent& event, bool pressed) const;

private :
    std::shared_ptr<dexode::EventBus> event_bus_;
    std::map<Keybinds, sf::Keyboard::Key> keymap_;
};


#endif //RASHNAWA_KEYBINDHANDLER_H
