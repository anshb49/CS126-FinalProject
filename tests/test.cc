// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cinder/Rand.h>

#include <mylibrary/engine.h>
#include <mylibrary/player.h>




Player user((std::string&)"initial name", 0);;
Monster monster;
Engine engine;
FlashMonster flash_monster;
Board board_piece;



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
  int speed = monster.GetSpeed();

  SECTION("Move Right Correct Distance") {
    monster.MoveRight();
    bool is_correct_distance = monster.GetXPosition() == 50+speed;
    REQUIRE(is_correct_distance);
  }

  SECTION("Move Left Correct Distance") {
    monster.MoveLeft();
    bool is_correct_distance = monster.GetXPosition() == 50-speed;
    REQUIRE(is_correct_distance);
  }

  SECTION("Move Up Correct Distance") {
    monster.MoveUp();
    bool is_correct_distance = monster.GetYPosition() == 50-speed;
    REQUIRE(is_correct_distance);
  }

  SECTION("Move Down Correct Distance") {
    monster.MoveDown();
    bool is_correct_distance = monster.GetYPosition() == 50+speed;
    REQUIRE(is_correct_distance);
  }

}

TEST_CASE("Check Correct Speed for Monster") {

  Monster monster1;
  Monster monster2;
  SECTION("Check Random Speed") {
    bool is_different_speed = monster1.GetSpeed() != monster2.GetSpeed();
    REQUIRE(is_different_speed);
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



TEST_CASE("Check Game Over Player Position") {
  user.SetGameOverPosition();

  SECTION("Check X Position") {
    bool is_correct_position = user.GetXPosition() == -1000;
    REQUIRE(is_correct_position);
  }

  SECTION("Check Y Position") {
    bool is_correct_position = user.GetYPosition() == 1000;
    REQUIRE(is_correct_position);
  }
}

TEST_CASE("Check If Stayed Within Board") {

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
    bool is_inside_boundary = user.GetXPosition() >= -15;
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

TEST_CASE("Checks If Monster Caught Player") {
  std::vector<Monster> monster_vector;

  SECTION("Normal Monster Did Catch Player") {
    user.SetXPosition(775);
    user.SetYPosition(790);

    monster.SetXPosition(770);
    monster.SetYPosition(785);
    monster_vector.push_back(monster);

    bool did_catch_player = engine.CheckIfCaught(user, monster_vector, flash_monster);
    REQUIRE(did_catch_player);
  }

  SECTION("Flash Monster Did Catch Player") {
    user.SetXPosition(775);
    user.SetYPosition(790);

    flash_monster.SetXPosition(770);
    flash_monster.SetYPosition(785);

    bool did_catch_player = engine.CheckIfCaught(user, monster_vector, flash_monster);
    REQUIRE(did_catch_player);
  }

  SECTION("Normal Monster Did Not Catch Player") {
    monster_vector.clear();

    user.SetXPosition(775);
    user.SetYPosition(790);

    monster.SetXPosition(1);
    monster.SetYPosition(1);
    monster_vector.push_back(monster);

    flash_monster.SetXPosition(1);
    flash_monster.SetXPosition(1);

    bool did_catch_player = engine.CheckIfCaught(user, monster_vector, flash_monster);
    REQUIRE(!did_catch_player);
  }

  SECTION("Flash Monster Did Not Catch Player") {
    user.SetXPosition(775);
    user.SetYPosition(790);

    flash_monster.SetXPosition(8);
    flash_monster.SetYPosition(8);

    bool did_catch_player = engine.CheckIfCaught(user, monster_vector, flash_monster);
    REQUIRE(!did_catch_player);
  }

}

TEST_CASE("Check If Player Burned") {
  std::vector<Board> board_vector;

  SECTION("Fire Did Burn Player") {
    user.SetXPosition(100);
    user.SetYPosition(100);

    board_piece.SetXPos(100);
    board_piece.SetYPos(100);

    board_vector.push_back(board_piece);

    bool did_burn_player = engine.CheckIfBurned(user, board_vector);
    REQUIRE(did_burn_player);
  }

  SECTION("Fire Did Not Burn Player") {
    board_vector.clear();

    user.SetXPosition(100);
    user.SetYPosition(100);

    board_piece.SetXPos(1);
    board_piece.SetYPos(1);

    board_vector.push_back(board_piece);

    bool did_burn_player = engine.CheckIfBurned(user, board_vector);
    REQUIRE(!did_burn_player);
  }
}


TEST_CASE("Check If Correct FlashMonster Position") {
  user.SetXPosition(400);
  user.SetYPosition(400);

  SECTION("Should Change Position") {
    FlashMonster flash2;
    flash2.SetXPosition(400);
    flash2.SetYPosition(400);
    engine.FixFlashPosition(user, flash2);

    bool did_change_position = flash_monster.GetXPosition() != 400
        && flash_monster.GetYPosition() != 400;
    REQUIRE(did_change_position);
  }
}
