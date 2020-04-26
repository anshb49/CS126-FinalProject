//
// Created by Ansh Bhalla on 4/23/20.
//

#ifndef FINALPROJECT_BOARD_H
#define FINALPROJECT_BOARD_H

#endif  // FINALPROJECT_BOARD_H

#include <cstdlib>

class Board {

 private:
  int x = (rand() % 800) + 1;
  int y = (rand() % 800) + 1;

 public:
  int GetXPos();
  int GetYPos();


};
