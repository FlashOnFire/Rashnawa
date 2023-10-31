#include "Game.h"
#include "screens/MainMenu.h"

Game::Game() {
    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1280, 720), "Rashnawa");
    _renderer = std::make_unique<Graphics::Renderer>(_window);
    _audioMgr.initialize();

    _currentScreen = std::make_unique<MainMenu>();

    _window->setFramerateLimit(240);

    if (!font.loadFromFile("../assets/fonts/Unitblock.ttf")) {
        std::cout << "Error: can't load font!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Game::run() {
    bool running = true;
    sf::Clock clock;

    while (running) {
        int deltaT = clock.restart().asMilliseconds();

        _audioMgr.update();

        handleEvents(running);

        _window->clear(sf::Color::White);

        if (_currentScreen.has_value()) {
            _currentScreen.value()->render(_window, font);
        } else {
            _renderer->render();
        }

        _window->display();
    }
}

void Game::handleEvents(bool &running) {
    sf::Event event{};
    while (_window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                running = false;
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        running = false;
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