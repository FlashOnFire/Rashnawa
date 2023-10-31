#include "Renderer.h"

#include <utility>

namespace Graphics {

    Renderer::Renderer(std::shared_ptr<sf::RenderWindow> window) {
        _window = std::move(window);
    }

    void Renderer::render() {
        // TODO: actually render
    }

} // Graphics