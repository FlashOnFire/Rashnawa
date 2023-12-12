#include "Renderer.h"

#include <utility>
#include <iostream>

namespace Graphics {

    Renderer::Renderer(std::shared_ptr<sf::RenderWindow> window) : window_(std::move(window)) {
        std::cout << "Created Renderer!" << std::endl;
    }

    void Renderer::render_game(const std::shared_ptr<World> &world) const {
        std::shared_ptr<Room> current_room = world->getCurrentRoom();
        sf::Vector2i size = current_room->getSize();
        auto background = sf::RectangleShape(sf::Vector2f(size));
        background.setTexture(current_room->getBackgroundTexture().get());
        window_->setView(sf::View(sf::FloatRect(0, 0, static_cast<float>(size.x),
                                                static_cast<float>(size.y))));
        window_->draw(background);
        auto entities = current_room->getEntities();
        for (const auto& entity : *entities) {
            window_->draw(*entity);
        }
    }

} // Graphics