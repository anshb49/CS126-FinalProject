
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
  /**
   * Gets the X position of the current piece of the board
   * @return - the x position
   */
  int GetXPos();

  /**
   * Gets the Y position of the current piece of the board
   * @return - the y position
   */
  int GetYPos();

  /**
   * Sets the current x position to a new x position
   * @param new_loc - the new x position
   */
  void SetXPos(int new_loc);

  /**
   * Sets the current y position to a new y position
   * @param new_loc - the new y position
   */
  void SetYPos(int new_loc);

};