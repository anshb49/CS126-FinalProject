//
// Created by Ansh Bhalla on 4/21/20.
//

#ifndef FINALPROJECT_MONSTER_H
#define FINALPROJECT_MONSTER_H

#endif  // FINALPROJECT_MONSTER_H

class Monster {

 private:
  int current_x = 0;
  int current_y = 0;
  int speed = 10;

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



};