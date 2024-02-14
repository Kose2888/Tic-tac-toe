#include "Player.h"

Player::Player() {
  X = false;
  O = true;
}

Player::~Player() {
}

void Player::setIsX(bool b) {
  X = b;
}

void Player::setIsO(bool b) {
  O = b;
}
