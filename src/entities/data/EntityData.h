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
    int max_life = 100;
    int life = max_life;
};

//only a try, you can modify what you want here

struct MonsterData {
    bool move_left = false;
    bool move_right = false;
    int life = 100;
};

union EntityData {
    PlayerData player;
};

#endif //ENTITYDATA_H
