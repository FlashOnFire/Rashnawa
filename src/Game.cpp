#include "Game.h"

#include <memory>
#include "screens/MainMenuScreen.h"
#include "screens/OptionsMenuScreen.h"
#include "events/Events.h"

Game::Game() {
    _eventBus = std::make_shared<dexode::EventBus>();

    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "Rashnawa");
    _window->setFramerateLimit(240);

    _audioMgr = std::make_shared<Audio::AudioManager>();
    _musicManager = std::make_unique<Audio::MusicManager>(_eventBus, _audioMgr);

    _renderer = std::make_unique<Graphics::Renderer>(_window);

    _keybindHandler = std::make_unique<KeybindHandler>(_eventBus);

    _audioMgr->initialize();
    _audioMgr->loadBank("../assets/audio/Master.bank");
    _audioMgr->loadBank("../assets/audio/Master.strings.bank");

    _eventBus->postpone<Events::ChangeScreen>({.from =  Screens::None, .to =  Screens::MainMenu});


    if (!_font->loadFromFile("../assets/fonts/Unitblock.ttf")) {
        std::cout << "Error: can't load font!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Game::run() {
    dexode::EventBus::Listener endGameListener{_eventBus};
    endGameListener.listen<Events::CloseGame>([this](const Events::CloseGame) {
        _running = false;
    });

    dexode::EventBus::Listener changeScreenListener{_eventBus};
    changeScreenListener.listen<Events::ChangeScreen>([this](const Events::ChangeScreen &e) {
        switch (e.to) {
            using enum Screens;

            case None:
                _currentScreen.reset();
                break;
            case MainMenu:
                _currentScreen = std::make_unique<MainMenuScreen>(_eventBus, _font);
                break;
            case OptionsMenu:
                _currentScreen = std::make_unique<OptionsMenuScreen>(_eventBus, _font, _window->getSize());
                break;
        }
    });

    sf::Clock clock;

    while (_running) {
        //int deltaT = clock.restart().asMilliseconds();

        _eventBus->process();
        _audioMgr->update();

        handleEvents();

        _window->clear(sf::Color::White);

        if (_currentScreen.has_value()) {
            _currentScreen.value()->render(_window);
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
            case sf::Event::Resized:
                _window->setView(sf::View(sf::FloatRect(0, 0, (float) event.size.width, (float) event.size.height)));

                if (_currentScreen.has_value()) {
                    _currentScreen.value()->onWindowResize(event.size);
                }
                break;
            case sf::Event::KeyPressed:
                _keybindHandler->handleEvent(event.key);
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        _eventBus->postpone(Events::EscapeBtn{});
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::MouseMoved:
                if (_currentScreen.has_value()) {
                    _currentScreen.value()->onMouseMove(event.mouseMove);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button != sf::Mouse::Button::Left)
                    continue;

                if (_currentScreen.has_value()) {
                    _currentScreen.value()->onMousePressed(event.mouseButton);
                }
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button != sf::Mouse::Button::Left)
                    continue;

                if (_currentScreen.has_value()) {
                    _currentScreen.value()->onMouseReleased(event.mouseButton);
                }
                break;
            default:
                break;
        }
    }
}
