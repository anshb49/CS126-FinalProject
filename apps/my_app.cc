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

using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::system_clock;


Player user;

cinder::gl::Texture2dRef image;
auto img = loadImage(cinder::app::loadAsset("mario_pic.png"));
const char kDbPath[] = "test_scoreboard.db";

std::chrono::high_resolution_clock::time_point t1 = std::chrono::
high_resolution_clock::now();

namespace myapp {

using cinder::app::KeyEvent;


DECLARE_string(name);

MyApp::MyApp() :
    leaderboard{cinder::app::getAssetPath(kDbPath).string()},
    user_name{FLAGS_name}
    {}


void MyApp::setup() {
}

void MyApp::update() {
  //Will be used when implement game over
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
}

void MyApp::keyDown(KeyEvent event) {
  switch (event.getCode()) {
    case KeyEvent::KEY_RIGHT: {
      user.MoveRight();
      break;
    }
    case KeyEvent::KEY_LEFT: {
      user.MoveLeft();
      break;
    }
    case KeyEvent::KEY_UP: {
      user.MoveUp();
      break;
    }
    case KeyEvent::KEY_DOWN: {
      user.MoveDown();
      break;
    }
  }
}

void MyApp::DrawUser() {

  cinder::gl::color(cinder::Color(0.8, 0.5, 0.007));  // red
  //cinder::gl::drawSolidCircle({user.GetXPosition(), user.GetYPosition()}, 30);
  image = cinder::gl::Texture2d::create(img);
  cinder::Rectf drawRect( user.GetXPosition(), user.GetYPosition(), user.GetXPosition() + 40, user.GetYPosition() + 50);
  cinder::gl::draw(image, drawRect);
}


void MyApp::DrawBoard() {
  cinder::gl::color(cinder::Color(1, 0, 0));  // red
  //cinder::gl::drawSolidCircle(getWindowCenter(), 10);
  cinder::gl::drawSolidRect( cinder::Rectf( getWindowWidth()/2-100.0f,
                                    getWindowHeight()/2-20.0f,
                                    getWindowWidth()/2+20.0f,
                                    getWindowHeight()/2+20.0f ) );

  cinder::gl::color(cinder::Color(0.8, 0.9, 0.5));
  cinder::gl::drawSolidRect( cinder::Rectf( getWindowWidth()-10.0f,
                                            getWindowHeight()/2-20.0f,
                                            getWindowWidth()/2+40.0f,
                                            getWindowHeight()/2+20.0f ) );
}



}
