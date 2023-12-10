#ifndef RASHNAWA_WORLD_H
#define RASHNAWA_WORLD_H

#include <vector>
#include <memory>
#include "Room.h"

class World {
public:
    World(std::string start_zone_name, std::string start_room_name);

private:
    std::vector<std::unique_ptr<Room>> loaded_room_;

};


#endif //RASHNAWA_WORLD_H
