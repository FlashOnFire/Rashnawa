#ifndef RASHNAWA_ROOM_H
#define RASHNAWA_ROOM_H

#include <SFML/Graphics.hpp>
#include "../entities/Entity.h"
#include "../entities/EntityBuilder.h"
#include "../world/TriggerBox.h"

class Room {
public:
    Room(const std::string &zone_name, const std::string &room_name, std::shared_ptr<EntityBuilder> builder);

    std::shared_ptr<std::vector<std::unique_ptr<Entity>>> getEntities();
    std::shared_ptr<std::vector<std::unique_ptr<TriggerBox>>> getTriggers();
    const std::shared_ptr<sf::Texture> getBackgroundTexture();
    sf::Vector2i getSize();

private:
    std::string zone_name_;
    std::string room_name_;

    sf::Vector2i size_;
    sf::Vector2i spawnpoint_;

    const std::shared_ptr<sf::Texture> background_texture_ = std::make_shared<sf::Texture>();

    std::shared_ptr<std::vector<std::unique_ptr<Entity>>> entities_ = std::make_shared<std::vector<std::unique_ptr<Entity>>>();
    std::shared_ptr<std::vector<std::unique_ptr<TriggerBox>>> triggers_ = std::make_shared<std::vector<std::unique_ptr<TriggerBox>>>();
};


#endif //RASHNAWA_ROOM_H
