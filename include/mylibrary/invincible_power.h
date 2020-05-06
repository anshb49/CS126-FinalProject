//
// Created by Ansh Bhalla on 5/5/20.
//

#ifndef FINALPROJECT_INVINCIBLE_POWER_H
#define FINALPROJECT_INVINCIBLE_POWER_H

#endif  // FINALPROJECT_INVINCIBLE_POWER_H
#include <stdlib.h>

class InvinciblePower {
 private:
  int current_x = (rand() % 775) + 100;
  int current_y = (rand() % 775) + 1;

 public:

  /**
   * Finds a random position value that would be visible on the board.
   * @return - a random position
   */
  int GetRandomPosition();

  /**
   * Gets the current x position of the potion.
   * @return - the current x position
   */
  int GetXPosition();

  /**
   * Gets the current y position of the potion.
   * @return - the current y position
   */
  int GetYPosition();

  /**
   * Sets the current x position to a new x position.
   * @param new_x - the new x position
   */
  void SetXPosition(int new_x);

  /**
   * Sets the current y position to a new y position.
   * @param new_y - the new y position
   */
  void SetYPosition(int new_y);
};
