//
// Created by flashonfire on 10/30/23.
//

#include "Renderer.h"

#include <utility>

namespace Graphics {

    Renderer::Renderer(std::shared_ptr<sf::RenderWindow> window) {
        _window = std::move(window);
    }

    void Renderer::render() {
        _window->clear();
        _window->display();
    }

} // Graphics