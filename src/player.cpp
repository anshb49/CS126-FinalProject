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
}

void Player::MoveLeft() {
  current_x = current_x - 15;
}

void Player::MoveUp() {
  current_y = current_y - 15;
}

void Player::MoveDown() {
  current_y = current_y + 15;
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




