// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cinder/Rand.h>

//#include <mylibrary/example.h>
#include <mylibrary/player.h>

Player user;

TEST_CASE("Change Direction Correctly") {

  user.SetXPosition(50);
  user.SetYPosition(50);

  SECTION("Move Right Correct Distance") {
    user.MoveRight();
    bool is_correct_distance = user.GetXPosition() == 65;
    REQUIRE(is_correct_distance);
  }

  SECTION("Move Left Correct Distance") {
    user.MoveLeft();
    bool is_correct_distance = user.GetXPosition() == 35;
    REQUIRE(is_correct_distance);
  }

  SECTION("Move Up Correct Distance") {
    user.MoveUp();
    bool is_correct_distance = user.GetYPosition() == 35;
    REQUIRE(is_correct_distance);
  }

  SECTION("Move Down Correct Distance") {
    user.MoveDown();
    bool is_correct_distance = user.GetYPosition() == 65;
    REQUIRE(is_correct_distance);
  }

}