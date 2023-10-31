#include "Player.h"

bool Player::isOnGround() const {
    return _onGround;
}

bool Player::isJumping() const {
    return _isJumping;
}

bool Player::isCrouching() const {
    return _isCrouching;
}

bool Player::isFacingLeft() const {
    return _facingLeft;
}

bool Player::isDashing() const {
    return _dashing;
}

bool Player::hasDashed() const {
    return _hasDashed;
}

bool Player::isUsingWeapon() const {
    return _usingWeapon;
}
