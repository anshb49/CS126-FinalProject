//
// Created by Ansh Bhalla on 4/18/20.
//
//#include <conio.h>

#include <iostream>
#include <sqlite_modern_cpp.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#include "mylibrary/player.h"

bool is_playing = true;

void Player::MoveRight() {

  current_x = current_x + 15;

  if (current_x >= 800-20) {
    current_x = current_x - 15;
  }

}

void Player::MoveLeft() {
  current_x = current_x - 15;

  if (current_x <= 0 - 10) {
    current_x = current_x + 15;
  }
}

void Player::MoveUp() {

  current_y = current_y - 15;

  if (current_y >= 0) {
    current_x = current_x + 15;
  }
}

void Player::MoveDown() {
  current_y = current_y + 15;

  if (current_y >= 800) {
    current_x = current_x - 15;
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





