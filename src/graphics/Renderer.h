#ifndef RASHNAWA_RENDERER_H
#define RASHNAWA_RENDERER_H

#include <memory>

#include <SFML/Graphics.hpp>
#include "../world/World.h"

namespace Graphics {

    class Renderer {
    public:
        explicit Renderer(std::shared_ptr<sf::RenderWindow> window);

        void render(std::shared_ptr<World> world) const;

    private:
        std::shared_ptr<sf::RenderWindow> window_;
    };

} // Graphics

#endif //RASHNAWA_RENDERER_H
