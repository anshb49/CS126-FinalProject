//
// Created by Ansh Bhalla on 4/27/20.
//
#include "mylibrary/flashmonster.h"
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
