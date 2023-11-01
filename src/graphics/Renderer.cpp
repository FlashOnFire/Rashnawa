#include "Renderer.h"

#include <utility>

namespace Graphics {

    Renderer::Renderer(std::shared_ptr<sf::RenderWindow> window) {
        _window = std::move(window);
    }

    void Renderer::render() {
        // TODO: actually render
        sf::RectangleShape shape;
        shape.setFillColor(sf::Color::Black);
        shape.setPosition(100, 100);
        shape.setSize(sf::Vector2f(250, 250));

        _window->draw(shape);
    }

} // Graphics