//
// Created by Ansh Bhalla on 4/21/20.
//

#ifndef FINALPROJECT_MONSTER_H
#define FINALPROJECT_MONSTER_H

#endif  // FINALPROJECT_MONSTER_H
#include <stdlib.h>

class Monster {

 private:
  int current_x = (rand() % 750) + 2;
  int current_y = (rand() % 750) + 2;
  int speed = (rand() % 7) + 2;

 public:

  int GetXPosition();
  int GetYPosition();

  void MoveRight();
  void MoveLeft();
  void MoveUp();
  void MoveDown();

  void SetXPosition(int loc);
  void SetYPosition(int loc);

  void SetSpeed(int new_speed);

  int GetSpeed();


  void MoveTowardsPlayer(int user_x, int user_y);



};