//
// Created by Ansh Bhalla on 5/5/20.
//

#ifndef FINALPROJECT_INVINCIBLE_POWER_H
#define FINALPROJECT_INVINCIBLE_POWER_H

#endif  // FINALPROJECT_INVINCIBLE_POWER_H
#include <stdlib.h>

class InvinciblePower {
 private:
  int current_x = (rand() + 775) + 1;
  int current_y = (rand() + 775) + 1;

 public:
  int ChangePosition();
  int GetXPosition();
  int GetYPosition();
  void SetXPosition(int new_x);
  void SetYPosition(int new_y);
};
