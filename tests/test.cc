// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cinder/Rand.h>

//#include <mylibrary/example.h>
#include <mylibrary/player.h>
#include <mylibrary/monster.h>

Player user;
Monster monster;

TEST_CASE("Change Direction Correctly for Player") {

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

TEST_CASE("Change Direction Correctly for Monster") {

  monster.SetXPosition(50);
  monster.SetYPosition(50);

  SECTION("Move Right Correct Distance") {
    monster.MoveRight();
    bool is_correct_distance = monster.GetXPosition() == 60;
    REQUIRE(is_correct_distance);
  }

  SECTION("Move Left Correct Distance") {
    monster.MoveLeft();
    bool is_correct_distance = monster.GetXPosition() == 40;
    REQUIRE(is_correct_distance);
  }

  SECTION("Move Up Correct Distance") {
    monster.MoveUp();
    bool is_correct_distance = monster.GetYPosition() == 40;
    REQUIRE(is_correct_distance);
  }

  SECTION("Move Down Correct Distance") {
    monster.MoveDown();
    bool is_correct_distance = monster.GetYPosition() == 60;
    REQUIRE(is_correct_distance);
  }

}

TEST_CASE("Check Correct Speed for Monster") {

  SECTION("Check Default Speed") {
    bool is_correct_speed = monster.GetSpeed() == 10;
    REQUIRE(is_correct_speed);
  }

  SECTION("Check Changed Speed") {
    monster.SetSpeed(40);
    bool is_correct_speed = monster.GetSpeed() == 40;
    REQUIRE(is_correct_speed);
  }

}