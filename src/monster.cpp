//
// Created by Ansh Bhalla on 4/21/20.
//

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

void MoveTowardsPlayer(int user_x, int user_y) {
  //Move Monster location based on the current Player location
}