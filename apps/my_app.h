// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include "mylibrary/leaderboard.h"

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

 private:
  LeaderBoard leaderboard;
  const std::string user_name;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
