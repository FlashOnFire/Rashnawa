#include "Game.h"
#include "screens/MainMenu.h"
#include "events/Events.hpp"

Game::Game() {
    _eventBus = std::make_shared<dexode::EventBus>();

    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1280, 720), "Rashnawa");
    _window->setFramerateLimit(240);

    _audioMgr = std::make_shared<Audio::AudioManager>();
    _renderer = std::make_unique<Graphics::Renderer>(_window);

    _audioMgr->initialize();
    _audioMgr->loadBank("../assets/audio/Master.bank");
    _audioMgr->loadBank("../assets/audio/Master.strings.bank");

    _currentScreen = std::make_unique<MainMenu>(_eventBus, _audioMgr);

    if (!font.loadFromFile("../assets/fonts/Unitblock.ttf")) {
        std::cout << "Error: can't load font!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Game::run() {
    dexode::EventBus::Listener endGameListener{_eventBus};
    endGameListener.listen<Events::CloseGame>([this](const Events::CloseGame &e) {
        _running = false;
    });

    dexode::EventBus::Listener changeScreenListener{_eventBus};
    changeScreenListener.listen<Events::GoInGame>([this](const Events::GoInGame &e) {
        _currentScreen.reset();
    });

    sf::Clock clock;

    while (_running) {
        int deltaT = clock.restart().asMilliseconds();

        _eventBus->process();
        _audioMgr->update();

        handleEvents();

        _window->clear(sf::Color::White);

        if (_currentScreen.has_value()) {
            _currentScreen.value()->render(_window, font);
        } else {
            _renderer->render();
        }

        _window->display();
    }
}

void Game::handleEvents() {
    sf::Event event{};
    while (_window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                _eventBus->postpone(Events::CloseGame{});
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        _eventBus->postpone(Events::CloseGame{});
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }


        if (_currentScreen.has_value()) {
            _currentScreen.value()->update(event);
        }
    }
}