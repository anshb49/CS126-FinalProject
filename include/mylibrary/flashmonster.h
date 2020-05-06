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
  /**
   * Changes the x position and y position to a random spot on the board.
   */
  void ChangePosition();

  /**
   * Gets the current x position.
   * @return - the current x position
   */
  int GetXPosition();

  /**
   * Gets the current y position.
   * @return - the current y position
   */
  int GetYPosition();

  /**
   * Sets the current x position to a new position.
   * @param position - the new position to be set to
   */
  void SetXPosition(int position);

  /**
   * Sets the current y position to a new position.
   * @param position - the new position to be set to
   */
  void SetYPosition(int position);
};
