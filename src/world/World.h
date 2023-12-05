#ifndef RASHNAWA_WORLD_H
#define RASHNAWA_WORLD_H

#include <vector>
#include <memory>
#include "Room.h"

class World {
public:

private:
    std::vector<std::unique_ptr<Room>> zone_;

};


#endif //RASHNAWA_WORLD_H
