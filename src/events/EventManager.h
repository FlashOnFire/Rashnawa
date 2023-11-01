#ifndef RASHNAWA_EVENTMANAGER_H
#define RASHNAWA_EVENTMANAGER_H

#include <functional>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "dexode/EventBus.hpp"

class EventManager {
public:
    EventManager(std::shared_ptr<dexode::EventBus> eventBus, std::shared_ptr<sf::RenderWindow> window);
    void handleEvents();
private:
    std::shared_ptr<dexode::EventBus> _eventBus;
    std::shared_ptr<sf::RenderWindow> _window;
};


#endif //RASHNAWA_EVENTMANAGER_H
