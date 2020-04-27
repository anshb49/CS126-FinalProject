// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cinder/Rand.h>

//#include <mylibrary/example.h>
#include <mylibrary/player.h>
#include <mylibrary/monster.h>
#include "mylibrary/board.h"

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


TEST_CASE("Contains random Board positions") {

  Board board1;
  Board board2;

  SECTION("Check X Positions Not Same") {
    bool is_different_x = board1.GetXPos() != board2.GetXPos();
    REQUIRE(is_different_x);
  }


}


TEST_CASE("Check Not Going Out Of Screen Boundaries") {
  user.SetXPosition(790);

  SECTION("Check Move Right Positions") {
    user.MoveRight();
    int xpos = user.GetXPosition();
    bool is_correct_pos = xpos <= 800;
    REQUIRE(is_correct_pos);
  }

  SECTION("Check Move Left Positions") {
    user.MoveLeft();
    int xpos = user.GetXPosition();
    bool is_correct_pos = xpos >= 0;
    REQUIRE(is_correct_pos);
  }

  SECTION("Check Move Up Positions") {
    user.MoveUp();
    int ypos = user.GetYPosition();
    bool is_correct_pos = ypos >= 0;
    REQUIRE(is_correct_pos);
  }

  SECTION("Check Move Down Positions") {
    user.MoveDown();
    int ypos = user.GetYPosition();
    bool is_correct_pos = ypos <= 800;
    REQUIRE(is_correct_pos);
  }


}



TEST_CASE("Check If Player Died From Lava") {

}

TEST_CASE("Check If Stayed Within Board") {
  //Check That user does not have a current location that is outside of the board
  //bounds

  SECTION("Stays in Right Boundary") {
    user.SetXPosition(775);
    user.SetYPosition(50);

    user.MoveRight();
    bool is_inside_boundary = user.GetXPosition() <= 800;
    REQUIRE(is_inside_boundary);
  }

  SECTION("Stays in Left Boundary") {
    user.SetXPosition(10);
    user.SetYPosition(50);

    user.MoveLeft();
    bool is_inside_boundary = user.GetXPosition() >= 0;
    REQUIRE(is_inside_boundary);
  }

  SECTION("Stays in Top Boundary") {
    user.SetXPosition(50);
    user.SetYPosition(15);

    user.MoveUp();
    bool is_inside_boundary = user.GetXPosition() >= 0;
    REQUIRE(is_inside_boundary);
  }

  SECTION("Stays in Bottom Boundary") {
    user.SetXPosition(775);
    user.SetYPosition(790);

    user.MoveDown();
    bool is_inside_boundary = user.GetXPosition() <= 800;
    REQUIRE(is_inside_boundary);
  }

}