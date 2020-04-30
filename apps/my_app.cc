// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <cinder/Font.h>
#include <cinder/Text.h>
#include <cinder/Vector.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <gflags/gflags.h>


#include <algorithm>
#include <chrono>
#include <cmath>
#include <string>



using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::system_clock;

Player player;
Monster monster;
FlashMonster flash_monster;


int lava_counter = 1;
int ninja_counter = 1;

int previous_time = 0;
int next_time = 20;


cinder::gl::Texture2dRef image;
auto img = loadImage(cinder::app::loadAsset("ninja_image.png"));

auto monster_img = loadImage(cinder::app::loadAsset("monster_pic.png"));

auto fire_end_img = loadImage(cinder::app::loadAsset("fire_gameover.png"));

const char kDbPath[] = "test_scoreboard.db";

std::chrono::high_resolution_clock::time_point t1 = std::chrono::
high_resolution_clock::now();

bool is_burned = false;
bool is_caught = false;

namespace myapp {

using cinder::app::KeyEvent;
vector<Board> board_pieces;
vector<Monster> monster_vector;
const int kNumFire = 14;


DECLARE_string(name);

MyApp::MyApp() :
    leaderboard{cinder::app::getAssetPath(kDbPath).string()},
    user_name{FLAGS_name}
{}


void MyApp::setup() {
  monster_vector.clear();
  for (int i = 0; i < kNumFire; i++) {
    Board current_piece;
    board_pieces.push_back(current_piece);
  }

  monster_vector.push_back(monster);
}

void MyApp::update() {

  std::chrono::high_resolution_clock::time_point t2 =
      std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> time_span =
      duration_cast<std::chrono::duration<double>>(t2 - t1);
  int time = time_span.count();

  if (time == next_time) {
      previous_time = next_time;
      next_time = next_time + 20;
      Monster new_monster;
      monster_vector.push_back(new_monster);
  }


  is_burned = CheckIfBurned(player, board_pieces);
  is_caught = CheckIfCaught(player, monster_vector);
  if (is_burned || is_caught) {
    leaderboard.AddScoreToLeaderBoard(user_name, time_span.count());
    return;
  }

}

void MyApp::draw() {
  cinder::gl::clear();

  if (is_burned || is_caught) {
    image = cinder::gl::Texture2d::create(fire_end_img);
    cinder::Rectf drawRect( 0.0f,
                            0.0f,
                            1000.0f,
                            1000.0f);
    cinder::gl::draw(image, drawRect);
    return;
  }

  DrawBackground();
  DrawUser();
  DrawBoard();
  DrawMonster();
  DrawFlashMonster();
}

void MyApp::keyDown(KeyEvent event) {
  if (is_burned || is_caught) {
    return;
  }
  switch (event.getCode()) {
    case KeyEvent::KEY_RIGHT: {
      player.MoveRight();
      break;
    }
    case KeyEvent::KEY_LEFT: {
      player.MoveLeft();
      break;
    }
    case KeyEvent::KEY_UP: {
      player.MoveUp();
      break;
    }
    case KeyEvent::KEY_DOWN: {
      player.MoveDown();
      break;
    }
  }
}

void MyApp::DrawUser() {
  if (is_burned || is_caught) {
    return;
  }
    auto back_texture =
            cinder::gl::Texture::create(ci::loadImage(loadAsset("running_ninja1.png")));

    if (ninja_counter == 1) {
        ninja_counter++;
    } else if (ninja_counter == 2) {
        back_texture =
                cinder::gl::Texture::create(ci::loadImage(loadAsset("running_ninja2.png")));
        ninja_counter++;
    } else if (ninja_counter == 3) {
        back_texture =
                cinder::gl::Texture::create(ci::loadImage(loadAsset("running_ninja3.png")));
        ninja_counter++;
    } else if (ninja_counter == 4) {
        back_texture =
                cinder::gl::Texture::create(ci::loadImage(loadAsset("running_ninja4.png")));
        ninja_counter++;
    } else if (ninja_counter == 5) {
        back_texture =
                cinder::gl::Texture::create(ci::loadImage(loadAsset("running_ninja5.png")));
        ninja_counter++;
    } else if (ninja_counter == 6) {
        back_texture =
                cinder::gl::Texture::create(ci::loadImage(loadAsset("running_ninja6.png")));
        ninja_counter = 1;
    }

    ci::gl::color(ci::ColorA(1, 1, 1, 1));

    cinder::gl::draw(back_texture, ci::Rectf({player.GetXPosition(),
                                              player.GetYPosition()},
                                             {player.GetXPosition() + 100,
                                              player.GetYPosition() + 100}));
}

void MyApp::DrawMonster() {

  auto back_texture =
      cinder::gl::Texture::create(ci::loadImage(loadAsset("monster_pic.png")));
  ci::gl::color(ci::ColorA(1, 1, 1, 1));


  for (int i = 0; i < monster_vector.size(); i++) {
    monster_vector[i].MoveTowardsPlayer(player.GetXPosition(),
                                        player.GetYPosition());
    cinder::gl::draw(back_texture,
                     ci::Rectf({monster_vector[i].GetXPosition(),
                                monster_vector[i].GetYPosition()},
                               {monster_vector[i].GetXPosition() + 65,
                                monster_vector[i].GetYPosition() + 65}));
  }
}

void MyApp::DrawFlashMonster() {
  auto back_texture =
      cinder::gl::Texture::create(ci::loadImage(loadAsset("monster_pic.png")));
  ci::gl::color(ci::ColorA(1, 1, 1, 1));

  flash_monster.ChangePosition();
  cinder::gl::draw(back_texture,
                   ci::Rectf({flash_monster.GetXPosition(),
                              flash_monster.GetYPosition()},
                             {flash_monster.GetXPosition() + 65,
                              flash_monster.GetYPosition() + 65}));
}



void MyApp::DrawBoard() {
  auto back_texture =
      cinder::gl::Texture::create(ci::loadImage(loadAsset("fire1.png")));
  if (lava_counter == 1) {
    lava_counter++;
  } else if (lava_counter == 2) {
    back_texture =
        cinder::gl::Texture::create(ci::loadImage(loadAsset("fire2.png")));
    lava_counter++;
  } else if (lava_counter == 3) {
    back_texture =
        cinder::gl::Texture::create(ci::loadImage(loadAsset("fire3.png")));
    lava_counter++;
  } else if (lava_counter == 4) {
    back_texture =
        cinder::gl::Texture::create(ci::loadImage(loadAsset("fire4.png")));
    lava_counter++;
  } else if (lava_counter == 5) {
    back_texture =
        cinder::gl::Texture::create(ci::loadImage(loadAsset("fire5.png")));
    lava_counter = 1;
  }

  ci::gl::color(ci::ColorA(1, 1, 1, 1));

  for (int i = 0; i < board_pieces.size(); i++) {
    cinder::gl::draw(back_texture, ci::Rectf({board_pieces[i].GetXPos(),
                                             board_pieces[i].GetYPos()},
                                             {board_pieces[i].GetXPos() + 75.0,
                                             board_pieces[i].GetYPos() + 75.0}));
  }

}

bool MyApp::CheckIfBurned(Player current_player, vector<Board> pieces) {
  for (int i = 0; i < pieces.size(); i++) {
    if (current_player.GetXPosition() >= pieces[i].GetXPos() - 50.0
        && current_player.GetXPosition() <= pieces[i].GetXPos() + 30.0
        && current_player.GetYPosition() >= pieces[i].GetYPos() - 60.0
        && current_player.GetYPosition() <= pieces[i].GetYPos() + 40.0) {
      return true;
    }
  }
  return false;
}


bool MyApp::CheckIfCaught(Player current_player, vector<Monster> monsters) {
  for (int i = 0; i < monster_vector.size(); i++) {
    if (abs(current_player.GetXPosition() - monster_vector[i].GetXPosition()) <= 50
    && abs(current_player.GetYPosition() - monster_vector[i].GetYPosition()) <= 50) {
      return true;
    }
  }

  if (abs(current_player.GetXPosition() - flash_monster.GetXPosition()) <= 40
      && abs(current_player.GetYPosition() - flash_monster.GetYPosition()) <= 40) {
    return true;
  }
  return false;
}




void MyApp::DrawBackground() {
  auto back_texture =
      cinder::gl::Texture::create(ci::loadImage(loadAsset("rock_texture.png")));
  ci::gl::color(ci::ColorA(1, 1, 1, 1));
  cinder::gl::draw(back_texture, ci::Rectf({0,
                                            0},
                                           {800,
                                            800}));
}

}