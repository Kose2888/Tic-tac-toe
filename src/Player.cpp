#include "Player.h"

Player::Player() {
  X = false;
  O = false;
}

Player::~Player() {
}

void Player::setIsX(bool b) {
  X = b;
}

void Player::setIsO(bool b) {
  O = b;
}
