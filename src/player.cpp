//
// Created by Ansh Bhalla on 4/18/20.
//
//#include <conio.h>

#include <iostream>
#include "mylibrary/player.h"

void Player::MoveRight() {
  current_x = current_x + 15;

  if (current_x >= 800-50) {
    current_x = current_x - 15;
  }
}

void Player::MoveLeft() {
  current_x = current_x - 15;

  if (current_x <= 0 - 40) {
    current_x = current_x + 15;
  }
}

void Player::MoveUp() {
  current_y = current_y - 15;

  if (current_y <= -25) {
    current_y = current_y + 15;
  }
}

void Player::MoveDown() {
  current_y = current_y + 15;

  if (current_y >= 800 - 70) {
    current_y = current_y - 15;
  }
}

int Player::GetMyScore() {
  return current_score;
}

int Player::GetXPosition() {
  return current_x;
}

int Player::GetYPosition() {
  return current_y;
}

void Player::SetXPosition(int loc) {
  current_x = loc;
}

void Player::SetYPosition(int loc) {
  current_y = loc;
}

void Player::SetScore(int new_score) {
  current_score = new_score;
}