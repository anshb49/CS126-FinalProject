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



cinder::gl::Texture2dRef image;
auto img = loadImage(cinder::app::loadAsset("mario_pic.png"));

auto wall_img = loadImage(cinder::app::loadAsset("final_neon_wall.png"));

auto monster_img = loadImage(cinder::app::loadAsset("monster_pic.png"));
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
  }
  std::chrono::high_resolution_clock::time_point t2 =
      std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> time_span =
      duration_cast<std::chrono::duration<double>>(t2 - t1);
  leaderboard.AddScoreToLeaderBoard(user_name, time_span.count());

}

void MyApp::draw() {
  cinder::gl::clear();


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
                          player.GetXPosition() + 40,
                          player.GetYPosition() + 50);

  cinder::gl::draw(image, drawRect);

}

void MyApp::DrawMonster() {
  image = cinder::gl::Texture2d::create(monster_img);

  monster.MoveTowardsPlayer(player.GetXPosition(), player.GetYPosition());

  cinder::Rectf drawRect( monster.GetXPosition(),
                          monster.GetYPosition(),
                          monster.GetXPosition() + 40,
                          monster.GetYPosition() + 50);

  cinder::gl::draw(image, drawRect);

}


void MyApp::DrawBoard() {
  double red = (rand() % 255) / 255;
  double green = (rand() % 255) / 255;
  double blue = (rand() % 255) / 255;
      //round((double) rand() / (1));
  cinder::gl::color(cinder::Color(1, 1, 1));  // red

  for (int i = 0; i < board_pieces.size(); i++) {
    //image = cinder::gl::Texture2d::create(wall_img);
    cinder::gl::drawSolidRect( cinder::Rectf( board_pieces[i].GetXPos(),
                                              board_pieces[i].GetYPos(),
                                              board_pieces[i].GetXPos() + 75.0,
                                              board_pieces[i].GetYPos() + 75.0) );
    //cinder::gl::draw(image, drawRect);
  }





  /**

  image = cinder::gl::Texture2d::create(wall_img);
  cinder::Rectf drawRect( 350.0f,
                          350.0f,
                          450.0f,
                          450.0f );
  cinder::gl::draw(image, drawRect);



  /**cinder::gl::drawSolidRect( cinder::Rectf( 350.0f,
                                    350.0f,
                                    450.0f,
                                    450.0f ) );
                                    */

  /*
  cinder::gl::drawSolidRect( cinder::Rectf( 200.0f,
                                            100.0f,
                                            230.0f,
                                            350.0f ) );
                                            */


  //cinder::gl::draw(image, drawRect);



  /*
  cinder::gl::drawSolidRect( cinder::Rectf( 570.0f,
                                            100.0f,
                                            600.0f,
                                            350.0f ) );
  //cinder::gl::draw(image, drawRect);


  cinder::gl::drawSolidRect( cinder::Rectf( 100.0f,
                                            100.0f,
                                            130.0f,
                                            350.0f ) );
  //cinder::gl::draw(image, drawRect);




  /**
  cinder::gl::drawSolidRect( cinder::Rectf( 670.0f,
                                            100.0f,
                                            700.0f,
                                            350.0f ) );





  cinder::gl::drawSolidRect( cinder::Rectf( 350.0f,
                                            200.0f,
                                            450.0f,
                                            230.0f ) );


  cinder::gl::drawSolidRect( cinder::Rectf( 350.0f,
                                            100.0f,
                                            450.0f,
                                            130.0f ) );



  cinder::gl::drawSolidRect( cinder::Rectf( 350.0f,
                                            600.0f,
                                            450.0f,
                                            570.0f ) );


  cinder::gl::drawSolidRect( cinder::Rectf( 350.0f,
                                            700.0f,
                                            450.0f,
                                            670.0f ) );




  cinder::gl::drawSolidRect( cinder::Rectf( 200.0f,
                                            700.0f,
                                            230.0f,
                                            450.0f ) );



  cinder::gl::drawSolidRect( cinder::Rectf( 570.0f,
                                            700.0f,
                                            600.0f,
                                            450.0f ) );


  cinder::gl::drawSolidRect( cinder::Rectf( 100.0f,
                                            700.0f,
                                            130.0f,
                                            450.0f ) );



  cinder::gl::drawSolidRect( cinder::Rectf( 670.0f,
                                            700.0f,
                                            700.0f,
                                            450.0f ) );




  /**
  cinder::gl::color(cinder::Color(0.8, 0.9, 0.5));
  cinder::gl::drawSolidRect( cinder::Rectf( getWindowWidth()-10.0f,
                                            getWindowHeight()/2-20.0f,
                                            getWindowWidth()/2+40.0f,
                                            getWindowHeight()/2+20.0f ) );
                                            */

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



}
