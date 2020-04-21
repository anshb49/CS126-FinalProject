//
// Created by Ansh Bhalla on 4/18/20.
//

#ifndef FINALPROJECT_PLAYER_H
#define FINALPROJECT_PLAYER_H

class Player {



 private:
  int current_score = 0;
  int current_x;
  int current_y;
 public:


  Player() {
    current_x = 0;
    current_y = 0;
  }

  int GetMyScore();
  int GetXPosition();
  int GetYPosition();

  void MoveRight();
  void MoveLeft();
  void MoveUp();
  void MoveDown();

  void SetXPosition(int loc);
  void SetYPosition(int loc);



};

#endif  // FINALPROJECT_PLAYER_H
