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
    bool _onGround = false;
    bool _isJumping = false;
    bool _isCrouching = false;
    bool _facingLeft = false;
    bool _dashing = false;
    bool _hasDashed = false;
    bool _usingWeapon = false;
    std::unique_ptr<Weapon> weapon;
};


#endif //RASHNAWA_PLAYER_H
