#include "Game.h"

#include <memory>
#include "screens/MainMenuScreen.h"
#include "screens/OptionsMenuScreen.h"
#include "events/Events.h"

Game::Game() {
    _eventBus = std::make_shared<dexode::EventBus>();

    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1280, 720), "Rashnawa");
    _window->setFramerateLimit(240);

    _eventManager = std::make_shared<EventManager>(_eventBus, _window);

    _audioMgr = std::make_shared<Audio::AudioManager>();
    _musicManager = std::make_unique<Audio::MusicManager>(_eventBus, _audioMgr);

    _renderer = std::make_unique<Graphics::Renderer>(_window);

    _audioMgr->initialize();
    _audioMgr->loadBank("../assets/audio/Master.bank");
    _audioMgr->loadBank("../assets/audio/Master.strings.bank");

    _eventBus->postpone<Events::ChangeScreen>({.from =  Screens::None, .to =  Screens::MainMenu});

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
    changeScreenListener.listen<Events::ChangeScreen>([this](const Events::ChangeScreen &e) {
        switch (e.to) {
            case None:
                _currentScreen.reset();
                break;
            case MainMenu:
                _currentScreen = std::make_unique<MainMenuScreen>(_eventBus);
                break;
            case OptionsMenu:
                _currentScreen = std::make_unique<OptionsMenuScreen>(_eventBus);
                break;
        }
    });

    sf::Clock clock;

    while (_running) {
        int deltaT = clock.restart().asMilliseconds();

        _eventBus->process();
        _audioMgr->update();

        _eventManager->handleEvents();

        _window->clear(sf::Color::White);

        if (_currentScreen.has_value()) {
            _currentScreen.value()->render(_window, font);
        } else {
            _renderer->render();
        }

        _window->display();
    }
}