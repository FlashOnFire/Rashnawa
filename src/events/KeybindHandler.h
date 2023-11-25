#ifndef RASHNAWA_KEYBINDHANDLER_H
#define RASHNAWA_KEYBINDHANDLER_H


#include <memory>
#include <SFML/Window/Event.hpp>
#include "dexode/EventBus.hpp"
#include "Keybinds.h"

class KeybindHandler {
public:
    explicit KeybindHandler(std::shared_ptr<dexode::EventBus> eventBus);

    void handleEvent(const sf::Event::KeyEvent &event);

private :
    std::shared_ptr<dexode::EventBus> _eventBus;
    std::map<Keybinds, sf::Keyboard::Key> _keymap;
};


#endif //RASHNAWA_KEYBINDHANDLER_H
