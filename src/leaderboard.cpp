//
// Created by Ansh Bhalla on 4/21/20.
//

#include <sqlite_modern_cpp.h>
#include "mylibrary/leaderboard.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

LeaderBoard::LeaderBoard(const string& db_path) : db_{db_path} {
  db_ << "CREATE TABLE if not exists leaderboard (\n"
         "  name  TEXT NOT NULL,\n"
         "  score INTEGER NOT NULL\n"
         ");";
}

void LeaderBoard::AddScoreToLeaderBoard(string name, int score) {
  // TODO(you): Add your query here.
  string player_name = name;
  int player_score = score;
  db_ << "insert into leaderboard (name,score) values (?,?);"
      << player_name
      << player_score;
}

/*
vector<Player> GetPlayers(sqlite::database_binder* rows) {
  vector<Player> players;

  for (auto&& row : *rows) {
    string name;
    size_t score;
    row >> name >> score;
    Player player = {name, score};
    players.push_back(player);
  }

  return players;
}

vector<Player> LeaderBoard::RetrieveHighScores(const size_t limit) {
  auto rows = db_ << "SELECT name,score FROM leaderboard order by score desc LIMIT (?);"
                  << limit;

  return GetPlayers(&rows);
}
 */
