
//
// Created by Ansh Bhalla on 4/23/20.
//

#ifndef FINALPROJECT_BOARD_H
#define FINALPROJECT_BOARD_H

#endif  // FINALPROJECT_BOARD_H

#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

class Board {

 private:
  int x = (rand() % 780) + 1;
  int y = (rand() % 780) + 1;

 public:
  int GetXPos();
  int GetYPos();
  int SetXPos(int new_loc);
  int SetYPos(int new_loc);

};