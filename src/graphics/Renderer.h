#ifndef RASHNAWA_RENDERER_H
#define RASHNAWA_RENDERER_H

#include <memory>

#include <SFML/Graphics.hpp>

namespace Graphics {

    class Renderer {
    public:
        Renderer(std::shared_ptr<sf::RenderWindow> ptr);
        void render();

    private:
        std::shared_ptr<sf::RenderWindow> _window;
    };

} // Graphics

#endif //RASHNAWA_RENDERER_H
