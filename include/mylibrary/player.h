//
// Created by Ansh Bhalla on 4/18/20.
//

#ifndef FINALPROJECT_PLAYER_H
#define FINALPROJECT_PLAYER_H

#include "mylibrary/board.h"

class Player {

 private:
  int current_score = 0;
  int current_x = 0;
  int current_y = 400;
 public:

  /**
   * Structure for Player
   * @param name - the name of the player
   * @param score - the score of the player
   */
  Player(std::string& name, size_t score) {
    current_x = 0;
    current_y = 400;
  }

  /**
   * Gets the score of the player.
   * @return - the current score of the player
   */
  int GetMyScore();

  /**
   * Gets the current x position of the player.
   * @return - the current x position
   */
  int GetXPosition();

  /**
   * Gets the current y position of the player.
   * @return - the current y position of the player
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
   * Moves the current y position up based on the speed constant
   * amount.
   */
  void MoveUp();

  /**
   * Moves the current x position down based on the speed constant
   * amount.
   */
  void MoveDown();

  /**
   * Sets the current x position to the new x position.
   * @param loc - the new x position
   */
  void SetXPosition(int loc);

  /**
   * Sets the current y position to the new y position.
   * @param loc
   */
  void SetYPosition(int loc);

  /**
   * Sets the score of the player to a new score
   * @param new_score - the new score of the player
   */
  void SetScore(int new_score);
};

#endif  // FINALPROJECT_PLAYER_H
