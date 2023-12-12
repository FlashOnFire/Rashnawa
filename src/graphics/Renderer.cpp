#include "Renderer.h"

#include <utility>
#include <iostream>

namespace Graphics {

    Renderer::Renderer(std::shared_ptr<sf::RenderWindow> window) : window_(std::move(window)) {
        std::cout << "Created Renderer!" << std::endl;
    }

    void Renderer::render(std::shared_ptr<World> world) const {
        std::shared_ptr<Room> current_room = world->getCurrentRoom();
        auto background = sf::RectangleShape(sf::Vector2f(window_->getSize()));
        background.setTexture(current_room->getBackgroundTexture().get());
        window_->draw(background);
        // TODO Call current_room->entities->draw(); (not implemented yet)
    }

} // Graphics