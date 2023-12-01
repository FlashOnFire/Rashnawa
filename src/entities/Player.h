#ifndef RASHNAWA_PLAYER_H
#define RASHNAWA_PLAYER_H


#include <memory>
#include "LivingEntity.h"
#include "weapons/Weapon.h"
#include "items/Item.h"

class Player : public LivingEntity {
public:


    [[nodiscard]] bool isOnGround() const;

    [[nodiscard]] bool isJumping() const;

    [[nodiscard]] bool isCrouching() const;

    [[nodiscard]] bool isFacingLeft() const;

    [[nodiscard]] bool isDashing() const;

    [[nodiscard]] bool hasDashed() const;

    [[nodiscard]] bool isUsingWeapon() const;

private:
    bool on_ground_ = false;
    bool is_jumping_ = false;
    bool is_crouching_ = false;
    bool facing_left_ = false;
    bool dashing_ = false;
    bool has_dashed_ = false;
    bool using_weapon_ = false;
    std::unique_ptr<Weapon> weapon;
};


#endif //RASHNAWA_PLAYER_H
