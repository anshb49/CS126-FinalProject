// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include "cinder/audio/Voice.h"

#include "mylibrary/leaderboard.h"
#include "mylibrary/player.h"
#include "mylibrary/engine.h"


using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::system_clock;

namespace myapp {

class MyApp : public cinder::app::App {
 public:

  /**
   * Initializes Application with window size and reads program arguments
   */
  MyApp();

  /**
   * Creates the pieces of the board, creates the intial monsters, and begins
   * the music before the program begins
   */
  void setup() override;

  /**
   * Updates the program each frame checking whether the program has ended or
   * not.
   */
  void update() override;

  /**
   * Draws the monsters, board, background, and player of the program onto
   * the window.
   */
  void draw() override;

  /**
   * Reads in the keyboard input and determines which direction to move the
   * monster in.
   */
  void keyDown(cinder::app::KeyEvent) override;

  /**
   * Draws the main player going through different images to create an animated
   * look/
   */
  void DrawUser();

  /**
   * Draws the game screen with the fire pieces using the pieces vector
   * along with each pieces X and Y position
   */
  void DrawFire();

  /**
   * Creates the monster on the board using the monster vector and also using
   * each X and Y position
   */
  void DrawMonster();

  /**
   * Draws the Welcome screen for a specific amount of time and then creates
   * the game screen with an image as the background.
   */
  void DrawBackground();

  /**
   * Draws the flash monster based on the X and Y position and also changes
   * the position after waiting for a specific amount of time.
   */
  void DrawFlashMonster();

  /**
   * Draws a timer on the top left part of the program window to display the
   * score of the current player
   */
  void DrawTimer();

  /**
   * Displays the score of the current player and also uses the leaderboard
   * database to display the top 3 scores in the game.
   */
  void DrawGameOverScreen();

  /**
   * Draws the potion on the screen based on the potion's current location.
   */
  void DrawPotion();

  /**
   *
   */
  void PrintLoadingScreen();

 private:
  LeaderBoard leaderboard;
  const std::string user_name;
  const size_t game_level;
  std::vector<int> top_player_scores;
  std::vector<std::string> top_player_names;

  bool should_start_time = true;
  bool is_burned = false;
  bool is_caught = false;
  bool is_invincible = false;

  int lava_counter = 1;
  int ninja_counter = 1;
  int flash_wait_counter = 0;
  int loading_counter = 1;
  int welcome_count = 0;

  int next_time = 15;
  bool did_add_score = false;
  bool printed_game_over = false;
  const int kAmount = 3;
  const int kWelcomeTime = 150;

  cinder::audio::VoiceRef background_music;
  cinder::audio::SourceFileRef back_sound = cinder::audio::
  load( cinder::app::loadAsset( "danger_song_short.m4a" ) );

  const string kInstructions = "Use the arrow keys to escape from the Monsters! "
                               "Beware of the Flash Monster and the Fire!";
  const string kLoading = "Loading";
  const string kWelcome = "Welcome To Escape";
  const string kGetReady = "GET READY";

  vector<Board> board_pieces;
  vector<Monster> monster_vector;
  int current_game_level = 0;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
