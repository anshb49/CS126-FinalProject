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



namespace myapp {

using cinder::app::KeyEvent;

MyApp::MyApp() {}

void MyApp::setup() {}

void MyApp::update() {}

void MyApp::draw() {
  DrawUser();
  DrawBoard();
}

void MyApp::keyDown(KeyEvent event) {}

void MyApp::DrawUser() {
  cinder::gl::color(cinder::Color(0.8, 0.5, 0.007));  // red
  cinder::gl::drawSolidCircle(getWindowCenter(), 10);
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
