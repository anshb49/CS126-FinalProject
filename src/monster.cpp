//
// Created by Ansh Bhalla on 4/21/20.
//
#include <iostream>
#include <cstdlib>


#include "mylibrary/monster.h"


void Monster::MoveRight() {
  current_x = current_x + speed;
}

void Monster::MoveLeft() {
  current_x = current_x - speed;
}

void Monster::MoveUp() {
  current_y = current_y - speed;
}

void Monster::MoveDown() {
  current_y = current_y + speed;
}


int Monster::GetSpeed() {
  return speed;
}

int Monster::GetXPosition() {
  return current_x;
}

int Monster::GetYPosition() {
  return current_y;
}

void Monster::SetXPosition(int loc) {
  current_x = loc;
}

void Monster::SetYPosition(int loc) {
  current_y = loc;
}

void Monster::SetSpeed(int new_speed) {
  speed = new_speed;
}

void Monster::MoveTowardsPlayer(int user_x, int user_y) {
  //Move Monster location based on the current Player location
  int x_distance = user_x - current_x;
  int y_distance = user_y - current_y;

  if (abs(x_distance) >= abs(y_distance)) {
    if (x_distance <= 0) {
      MoveLeft();
    } else {
      MoveRight();
    }
  } else {
    if (y_distance <= 0) {
      MoveUp();
    } else {
      MoveDown();
    }
  }


}