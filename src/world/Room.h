#ifndef RASHNAWA_ROOM_H
#define RASHNAWA_ROOM_H

#include <SFML/Graphics.hpp>
#include "../entities/Entity.h"
#include "../entities/EntityBuilder.h"
#include "../world/TriggerBox.h"

class Room {
public:
    Room(const std::string& zone_name, const std::string& room_name, std::shared_ptr<EntityBuilder> builder);

    std::shared_ptr<std::vector<std::unique_ptr<Entity>>> getEntities();
    std::shared_ptr<std::vector<std::unique_ptr<TriggerBox>>> getTriggers();

private:
    std::string zone_name_;
    std::string room_name_;

    sf::Vector2i size_;
    sf::Vector2i spawnpoint_;

    const std::unique_ptr<sf::Texture> background_texture_ = std::make_unique<sf::Texture>();

    std::shared_ptr<std::vector<std::unique_ptr<Entity>>> entities_;
    std::shared_ptr<std::vector<std::unique_ptr<TriggerBox>>> triggers_;
};


#endif //RASHNAWA_ROOM_H
