// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <cinder/Font.h>
#include <cinder/Text.h>
#include <cinder/Vector.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <string>

#include "mylibrary/player.h"

Player user;

cinder::gl::Texture2dRef image;
auto img = loadImage(cinder::app::loadAsset("mario_pic.png"));


namespace myapp {

using cinder::app::KeyEvent;

MyApp::MyApp() {}

void MyApp::setup() {
}

void MyApp::update() {}

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
  cinder::gl::drawSolidCircle({user.GetXPosition(), user.GetYPosition()}, 30);
  //image = cinder::gl::Texture2d::create(img);
  //cinder::Rectf drawRect( user.GetXPosition(), user.GetYPosition(), user.GetXPosition() + 40, user.GetYPosition() + 50);
  //cinder::gl::draw(image, drawRect);
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
