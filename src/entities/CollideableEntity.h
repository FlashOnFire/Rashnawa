#ifndef RASHNAWA_COLLIDEABLEENTITY_H
#define RASHNAWA_COLLIDEABLEENTITY_H


#include "Entity.h"
#include "Hitbox.h"

class CollideableEntity : public Entity {
public:
    [[nodiscard]] const Hitbox &getHitbox() const;

    void setHitbox(const Hitbox &hitbox);

private:
    Hitbox _hitbox;
};


#endif //RASHNAWA_COLLIDEABLEENTITY_H
