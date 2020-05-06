//
// Created by Ansh Bhalla on 4/21/20.
//

#ifndef FINALPROJECT_MONSTER_H
#define FINALPROJECT_MONSTER_H

#endif  // FINALPROJECT_MONSTER_H
#include <stdlib.h>
#include <string>

class Monster {

 private:
  int current_x = (rand() % 750) + 100;
  int current_y = (rand() % 750) + 50;
  int speed = (rand() % 7) + 2;

 public:

  /**
   * Gets the current x position.
   * @return - the current x position.
   */
  int GetXPosition();

  /**
   * Gets the current y position.
   * @return - the current y position
   */
  int GetYPosition();

  /**
   * Moves the current x position to the right based on the speed constant
   * amount.
   */
  void MoveRight();

  /**
   * Moves the current x position to the left based on the speed constant
   * amount.
   */
  void MoveLeft();

  /**
   * Moves the current y position up based on the speed constant amount.
   */
  void MoveUp();

  /**
   * Moves the current y position down based on the speed constant amount.
   */
  void MoveDown();

  /**
   * Sets the current x position to a new position.
   * @param loc - the new x position
   */
  void SetXPosition(int loc);

  /**
   * Sets the current y position to a new position.
   * @param loc - the new y position
   */
  void SetYPosition(int loc);

  /**
   * Sets the speed to a new speed value.
   * @param new_speed - the new speed (how many spaces to move by)
   */
  void SetSpeed(int new_speed);

  /**
   * Gets the current speed of the monster.
   * @return - the current speed of the monster
   */
  int GetSpeed();

  /**
   * Moves the monster in the direction closest to the current player
   * position.
   * @param user_x - the current x position of the user.
   * @param user_y - the current y position of the user.
   * @return - the direction that the monster moved in
   */
  std::string MoveTowardsPlayer(int user_x, int user_y);
};