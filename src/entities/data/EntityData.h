#ifndef ENTITYDATA_H
#define ENTITYDATA_H

struct PlayerData {
    bool on_ground = false;
    bool move_left = false;
    bool move_right = false;
    bool jumping = false;
    bool crouching = false;
    bool facing_left = false;
    bool dashing = false;
    bool has_dashed = false;
    bool using_weapon = false;
};

union EntityData {
    PlayerData player;
};

#endif //ENTITYDATA_H
