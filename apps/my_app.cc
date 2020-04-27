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

#include "mylibrary/player.h"
#include "mylibrary/monster.h"


using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::system_clock;

Player player;
Monster monster;

int lava_counter = 1;


cinder::gl::Texture2dRef image;
auto img = loadImage(cinder::app::loadAsset("mario_pic.png"));

auto wall_img = loadImage(cinder::app::loadAsset("final_neon_wall.png"));

auto monster_img = loadImage(cinder::app::loadAsset("monster_pic.png"));

auto fire_end_img = loadImage(cinder::app::loadAsset("fire_gameover.png"));

const char kDbPath[] = "test_scoreboard.db";

std::chrono::high_resolution_clock::time_point t1 = std::chrono::
high_resolution_clock::now();

bool is_burned = false;

namespace myapp {

using cinder::app::KeyEvent;

vector<Board> board_pieces;


DECLARE_string(name);

MyApp::MyApp() :
    leaderboard{cinder::app::getAssetPath(kDbPath).string()},
    user_name{FLAGS_name}
{}


void MyApp::setup() {
  for (int i = 0; i < 10; i++) {
    Board current_piece;
    board_pieces.push_back(current_piece);
  }
}

void MyApp::update() {
  //Will be used when implement game over

  is_burned = CheckIfBurned(player, board_pieces);


  if (is_burned) {
    std::cout << "burned in lava";
    std::chrono::high_resolution_clock::time_point t2 =
        std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span =
        duration_cast<std::chrono::duration<double>>(t2 - t1);
    leaderboard.AddScoreToLeaderBoard(user_name, time_span.count());
  }

}

void MyApp::draw() {
  cinder::gl::clear();

  if (is_burned) {
    image = cinder::gl::Texture2d::create(fire_end_img);
    cinder::Rectf drawRect( 0.0f,
                            0.0f,
                            800.0f,
                            800.0f);
    cinder::gl::draw(image, drawRect);
    return;
  }

  DrawBackground();
  DrawUser();
  DrawBoard();
  DrawMonster();
}

void MyApp::keyDown(KeyEvent event) {
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
  cinder::gl::disableDepthRead();
  cinder::gl::disableDepthWrite();

  //cinder::gl::drawSolidCircle({user.GetXPosition(), user.GetYPosition()}, 30);
  image = cinder::gl::Texture2d::create(img);


  cinder::Rectf drawRect( player.GetXPosition(),
                          player.GetYPosition(),
                          player.GetXPosition() + 65,
                          player.GetYPosition() + 65);

  cinder::gl::draw(image, drawRect);

}

void MyApp::DrawMonster() {
  image = cinder::gl::Texture2d::create(monster_img);

  monster.MoveTowardsPlayer(player.GetXPosition(), player.GetYPosition());

  cinder::Rectf drawRect( monster.GetXPosition(),
                          monster.GetYPosition(),
                          monster.GetXPosition() + 65,
                          monster.GetYPosition() + 65);

  cinder::gl::draw(image, drawRect);

}


void MyApp::DrawBoard() {
  auto back_texture =
      cinder::gl::Texture::create(ci::loadImage(loadAsset("lava1.png")));
  if (lava_counter == 1) {
    lava_counter++;
  } else if (lava_counter == 2) {
    back_texture =
        cinder::gl::Texture::create(ci::loadImage(loadAsset("lava2.png")));
    lava_counter++;
  } else if (lava_counter == 3) {
    back_texture =
        cinder::gl::Texture::create(ci::loadImage(loadAsset("lava3.png")));
    lava_counter++;
  } else if (lava_counter == 4) {
    back_texture =
        cinder::gl::Texture::create(ci::loadImage(loadAsset("lava4.png")));
    lava_counter++;
  } else if (lava_counter == 5) {
    back_texture =
        cinder::gl::Texture::create(ci::loadImage(loadAsset("lava5.png")));
    lava_counter++;
  } else if (lava_counter == 6) {
    back_texture =
        cinder::gl::Texture::create(ci::loadImage(loadAsset("lava6.png")));
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
    if (current_player.GetXPosition() >= pieces[i].GetXPos()
        && current_player.GetXPosition() <= pieces[i].GetXPos() + 75.0
        && current_player.GetYPosition() >= pieces[i].GetYPos()
        && current_player.GetYPosition() <= pieces[i].GetYPos() + 75.0) {
      return true;
    }
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


//From Snake Project
template <typename C>
void PrintText(const string& text, const C& color, const cinder::ivec2& size,
               const cinder::vec2& loc) {
  cinder::gl::color(color);

  auto box = TextBox()
      .alignment(TextBox::CENTER)
      .font(cinder::Font(kNormalFont, 30))
      .size(size)
      .color(color)
      .backgroundColor(ColorA(0, 0, 0, 0))
      .text(text);

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}



}