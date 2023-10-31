#ifndef RASHNAWA_WEAPON_H
#define RASHNAWA_WEAPON_H


class Weapon {
public:
    virtual void attack();
private:
    float _windupTime;
    float _damage;
};


#endif //RASHNAWA_WEAPON_H
