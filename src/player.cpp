//
// Created by Ansh Bhalla on 4/18/20.
//
//#include <conio.h>

#include <MacTypes.h>
#include <sqlite_modern_cpp.h>

#include <iostream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#include "mylibrary/player.h"

bool is_playing = true;

void Player::MoveRight() {

  current_x = current_x + 15;

  if (CanMoveRight() || current_x >= 800-20) {
    current_x = current_x - 15;
  }
}

void Player::MoveLeft() {
  current_x = current_x - 15;

  if (CanMoveRight() || current_x <= 0 - 10) {
    current_x = current_x + 15;
  }
  /**
  if (!IsInWall()) {
    current_x = current_x - 15;

    if (current_x <= 0 - 10) {
      current_x = current_x + 15;
    }
  }
   */
}

void Player::MoveUp() {
  std::cout << "x:" << current_x << std::endl;
  std::cout << "y:" << current_y << std::endl;
  current_y = current_y - 15;

  if (CanMoveRight() || current_y >= -15) {
    current_y = current_y + 15;
  }
  /**

  if (!IsInWall()) {
    current_y = current_y - 15;

    if (current_y <= -15) {
      current_y = current_y + 15;
    }
  }
   */
}

void Player::MoveDown() {
  current_y = current_y + 15;


  if (current_y >= 800 - 15) {
    current_y = current_y - 15;
  }
}


bool Player::CanMoveRight() {
  //Middle block
  if (current_x >= 310 && current_x <= 450 && current_y >= 300 && current_y <= 450) {
    return true;
  }
  return false;
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







