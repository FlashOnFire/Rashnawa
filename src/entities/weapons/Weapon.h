#ifndef RASHNAWA_WEAPON_H
#define RASHNAWA_WEAPON_H


class Weapon {
public:
    virtual ~Weapon() = default;

    virtual void attack() = 0;

private:
    float windup_time_ = 0;
    float damage_ = 0;
};


#endif //RASHNAWA_WEAPON_H
