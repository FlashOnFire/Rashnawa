#ifndef RASHNAWA_ROOM_H
#define RASHNAWA_ROOM_H

#include <SFML/Graphics.hpp>
#include "../entities/Entity.h"
#include "../world/TriggerBox.h"

class Room {
public:
    Room(std::string zone_number, std::string room_number);

private:
    sf::Vector2i size_;

    const std::unique_ptr<sf::Texture> background_texture_ = std::make_unique<sf::Texture>();

    std::vector<std::unique_ptr<Entity>> entities_;
    std::vector<std::unique_ptr<TriggerBox>> triggers_;
};


#endif //RASHNAWA_ROOM_H
