#ifndef RASHNAWA_WEAPON_H
#define RASHNAWA_WEAPON_H


class Weapon {
public:
    virtual ~Weapon() = default;
    virtual void attack() = 0;

private:
    float _windupTime = 0;
    float _damage = 0;
};


#endif //RASHNAWA_WEAPON_H
