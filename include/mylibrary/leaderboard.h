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
  explicit LeaderBoard(const std::string& db_path);

  void AddScoreToLeaderBoard(string name, int score);

  vector<int> RetrieveHighScores(const size_t limit);
  vector<string> RetrieveHighNames(const size_t limit);


 private:
  sqlite::database db_;
};