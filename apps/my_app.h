// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>

#include "mylibrary/leaderboard.h"
#include "mylibrary/player.h"
#include "mylibrary/engine.h"

namespace myapp {

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;

  void DrawUser();
  void DrawBoard();
  void DrawMonster();
  void DrawBackground();
  void DrawFlashMonster();
  void DrawTimer();

  bool CheckIfBurned(Player current_player, vector<Board> pieces);
  bool CheckIfCaught(Player current_player, vector<Monster> monsters);
  void DrawGameOverScreen();

  int DecideGameLevel();

 private:
  LeaderBoard leaderboard;
  const std::string user_name;
  const size_t game_level;
  std::vector<int> top_player_scores;
  std::vector<std::string> top_player_names;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
