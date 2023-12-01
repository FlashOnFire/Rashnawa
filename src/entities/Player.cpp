#include "Player.h"

bool Player::isOnGround() const {
    return on_ground_;
}

bool Player::isJumping() const {
    return is_jumping_;
}

bool Player::isCrouching() const {
    return is_crouching_;
}

bool Player::isFacingLeft() const {
    return facing_left_;
}

bool Player::isDashing() const {
    return dashing_;
}

bool Player::hasDashed() const {
    return has_dashed_;
}

bool Player::isUsingWeapon() const {
    return using_weapon_;
}
