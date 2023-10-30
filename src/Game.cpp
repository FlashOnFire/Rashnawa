#include "Game.h"

Game::Game() {
    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Rashnawa");
    _renderer = std::make_unique<Graphics::Renderer>(_window);
    _audioMgr.initialize();

}

void Game::run() {
    bool running = true;

    sf::Event event;

    while (running) {
        _audioMgr.update();

        while (_window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    running = false;
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            running = false;
                        case sf::Keyboard::A:
                            std::cout << "Pressed A" << std::endl;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        _world.update();
        _renderer->render();
    }
}