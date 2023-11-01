#include <iostream>
#include <SFML/Window/Event.hpp>
#include "EventManager.h"
#include "Events.h"

EventManager::EventManager(std::shared_ptr<dexode::EventBus> eventBus, std::shared_ptr<sf::RenderWindow> window) : _eventBus(std::move(eventBus)), _window(std::move(window)) {
    std::cout << "Created EventManager!" << std::endl;
}

void EventManager::handleEvents() {
    sf::Event event{};
    while (_window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                _eventBus->postpone(Events::CloseGame{});
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        _eventBus->postpone(Events::EscapeBtn{});
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::MouseButtonPressed:
                _eventBus->postpone<Events::MouseButtonPressed>({.event = event.mouseButton});
            case sf::Event::MouseMoved:
                _eventBus->postpone(event.mouseMove);
                break;
            default:
                break;
        }
    }
}


