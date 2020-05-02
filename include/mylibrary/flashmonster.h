//
// Created by Ansh Bhalla on 4/23/20.
//

#ifndef FINALPROJECT_FLASHMONSTER_H
#define FINALPROJECT_FLASHMONSTER_H


#endif  // FINALPROJECT_FLASHMONSTER_H


class FlashMonster {
 private:
  int current_x = 0;
  int current_y = 0;

 public:
  void ChangePosition();
  int GetXPosition();
  int GetYPosition();
  void SetXPosition(int position);
  void SetYPosition(int position);
};
