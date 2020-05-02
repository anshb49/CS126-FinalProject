//
// Created by Ansh Bhalla on 4/25/20.
//

#include "mylibrary/board.h"

int Board::GetXPos() {
  return x;
}

int Board::GetYPos() {
  return y;
}

int Board::SetXPos(int new_loc) {
  x = new_loc;
}

int Board::SetYPos(int new_loc) {
  y = new_loc;
}
