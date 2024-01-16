#ifndef RASHNAWA_WORLD_H
#define RASHNAWA_WORLD_H

#include <vector>
#include <memory>
#include "Room.h"
#include "../src/entities/EntityBuilder.h"

class World {
public:
    explicit World(std::shared_ptr<dexode::EventBus> event_bus);

    [[nodiscard]] std::shared_ptr<Room> getCurrentRoom() const;

    void load(const std::string &zone_name, const std::string &room_name);

private:
    std::shared_ptr<dexode::EventBus> event_bus_;

    std::shared_ptr<EntityBuilder> entity_builder_;

    std::vector<std::shared_ptr<Room>> loaded_rooms_;

    std::string current_zone_name_;

    std::shared_ptr<Room> current_room_;
};


#endif //RASHNAWA_WORLD_H
