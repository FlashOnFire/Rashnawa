#ifndef RASHNAWA_WORLD_H
#define RASHNAWA_WORLD_H

#include <vector>
#include <memory>
#include "Room.h"
#include "../src/entities/EntityBuilder.h"

class World {
public:
    World(std::shared_ptr<dexode::EventBus> event_bus);

    void load(std::string zone_name, std::string room_name);

private:
    std::shared_ptr<dexode::EventBus> event_bus_;

    std::shared_ptr<EntityBuilder> entity_builder_;

    std::vector<std::unique_ptr<Room>> loaded_rooms_;

    std::unique_ptr<Room> current_room_;

};


#endif //RASHNAWA_WORLD_H
