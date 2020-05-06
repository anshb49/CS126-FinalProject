//
// Created by Ansh Bhalla on 4/27/20.
//
#include "mylibrary/flashmonster.h"
#include "mylibrary/monster.h"
#include <stdlib.h>

void FlashMonster::ChangePosition() {
  current_x = (rand() % 800) + 1;
  current_y = rand() % 800 + 1;
}

int FlashMonster::GetXPosition() {
  return current_x;
}

int FlashMonster::GetYPosition() {
  return current_y;
}

void FlashMonster::SetXPosition(int loc) {
  current_x = loc;
}

void FlashMonster::SetYPosition(int loc) {
  current_y = loc;
}