//
// Created by Ansh Bhalla on 5/5/20.
//

#include "mylibrary/invincible_power.h"


int InvinciblePower::ChangePosition() {
  return (rand() + 775) + 1;
}

int InvinciblePower::GetXPosition() {
  return current_x;
}

int InvinciblePower::GetYPosition() {
  return current_y;
}

void InvinciblePower::SetXPosition(int new_x) {
  current_x = new_x;
}

void InvinciblePower::SetYPosition(int new_y) {
  current_y = new_y;
}