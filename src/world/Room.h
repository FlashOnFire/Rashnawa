#ifndef RASHNAWA_ROOM_H
#define RASHNAWA_ROOM_H

#include <SFML/Graphics.hpp>
#include "../entities/Entity.h"
#include "../entities/EntityBuilder.h"
#include "../world/TriggerBox.h"

class Room {
public:
    Room(std::string zone_name, std::string room_name, const std::shared_ptr<EntityBuilder> &builder);

    [[nodiscard]] std::shared_ptr<std::vector<std::unique_ptr<Entity>>> getEntities() const;

    [[nodiscard]] std::shared_ptr<std::vector<std::unique_ptr<TriggerBox>>> getTriggers() const;

    [[nodiscard]] std::shared_ptr<sf::Texture> getBackgroundTexture() const;

    [[nodiscard]] sf::Vector2i getSize() const;

private:
    std::string zone_name_;
    std::string room_name_;

    sf::Vector2i size_;
    sf::Vector2i spawn_point_;

    const std::shared_ptr<sf::Texture> background_texture_ = std::make_shared<sf::Texture>();

    std::shared_ptr<std::vector<std::unique_ptr<Entity>>> entities_ = std::make_shared<std::vector<std::unique_ptr<Entity>>>();
    std::shared_ptr<std::vector<std::unique_ptr<TriggerBox>>> triggers_ = std::make_shared<std::vector<std::unique_ptr<TriggerBox>>>();
};


#endif //RASHNAWA_ROOM_H
