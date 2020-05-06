//
// Created by Ansh Bhalla on 4/21/20.
//

#ifndef FINALPROJECT_LEADERBOARD_H
#define FINALPROJECT_LEADERBOARD_H

#endif  // FINALPROJECT_LEADERBOARD_H

#include <sqlite_modern_cpp.h>

#include <string>
#include <vector>

#include "player.h"

using std::string;
using std::vector;

class LeaderBoard {
 public:
  /**
   * Creates the leaderboard using the database.
   * @param db_path - the path of the database file to be used
   */
  explicit LeaderBoard(const std::string& db_path);

  /**
   * Adds the current name of the player and their score into the leaderboard.
   * @param name - the current name of the player
   * @param score - the score they got on the game
   */
  void AddScoreToLeaderBoard(string name, int score);

  /**
   * Goes through the SQL database and returns the top scores as a vector based
   * on the limit value.
   * @param limit - the number of top scores wanted
   * @return - the vector of the top scores
   */
  vector<int> RetrieveHighScores(const size_t limit);

  /**
   * Goes through the SQL database and returns the top names based on score
   * as a vector based on the limit value
   * @param limit - the number of top names wanted
   * @return - the vector of the player names with the top scores
   */
  vector<string> RetrieveHighNames(const size_t limit);

 private:
  sqlite::database db_;
};