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
#include <string>
using cinder::TextBox;

Engine engine;
Player player((string&)"a name", 0);

const char kBoldFont[] = "Arial-BoldMT";
const char kDbPath[] = "test_scoreboard.db";

cinder::gl::Texture2dRef image;
auto fire_end_img = loadImage(cinder::app::
    loadAsset("fire_gameover.png"));
std::chrono::high_resolution_clock::time_point t1 = std::chrono::
high_resolution_clock::now();
std::chrono::high_resolution_clock::time_point start_potion_time = std::chrono::
high_resolution_clock::now();


namespace myapp {

using cinder::app::KeyEvent;
vector<Board> board_pieces;
vector<Monster> monster_vector;
int current_game_level = 0;


DECLARE_string(name);
DECLARE_uint32(level);

MyApp::MyApp() :
    leaderboard{cinder::app::getAssetPath(kDbPath).string()},
    user_name{FLAGS_name},
    game_level{FLAGS_level}{};

void MyApp::setup() {
  current_game_level = engine.DecideGameLevel(game_level);
  monster_vector.clear();
  board_pieces.clear();

  for (int i = 0; i < current_game_level; i++) {
    Board current_piece;
    bool is_on_player = current_piece.GetXPos() <= 15
        || (current_piece.GetYPos() >= 375 && current_piece.GetYPos() <= 415);
    if (is_on_player) {
      current_piece.SetXPos(rand() % 750 + 40);
      current_piece.SetXPos(rand() % 750 + 30);
    }

    while (abs(engine.power.GetXPosition() - current_piece.GetXPos()) <= 15
    && abs(engine.power.GetYPosition() - current_piece.GetYPos()) <= 15) {
      engine.power.SetXPosition(engine.power.GetRandomPosition());
      engine.power.SetYPosition(engine.power.GetRandomPosition());
    }
    board_pieces.push_back(current_piece);
  }
  monster_vector.push_back(engine.monster);

  background_music = cinder::audio::Voice::create(back_sound);
  background_music->start();
}

void MyApp::update() {
  std::chrono::high_resolution_clock::time_point t2 =
      std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> time_span =
      duration_cast<std::chrono::duration<double>>(t2 - t1);
  std::chrono::duration<double> potion_span =
      duration_cast<std::chrono::duration<double>>(t2 - start_potion_time);
  int time = time_span.count();
  int potion_time = potion_span.count();


  if (potion_time >= 7) {
    is_invincible = false;
  }

  if (time == next_time) {
      next_time = next_time + 15;
      Monster new_monster;
      monster_vector.push_back(new_monster);
  }

  is_burned = engine.CheckIfBurned(player, board_pieces);
  is_caught = engine.CheckIfCaught(player, monster_vector, engine.flash_monster);
  if ((is_burned || is_caught) && !did_add_score && is_invincible==false) {
    player.SetScore(time);
    leaderboard.AddScoreToLeaderBoard(user_name, player.GetMyScore());
    did_add_score = true;
    return;
  }
}

void MyApp::draw() {
  if (welcome_count <= kWelcomeTime) {
    cinder::gl::clear();
    DrawBackground();
  } else {
    if ((is_burned || is_caught) && is_invincible==false) {
      top_player_scores = leaderboard.RetrieveHighScores(kAmount);
      top_player_names = leaderboard.RetrieveHighNames(kAmount);
      DrawGameOverScreen();
      return;
    }

    if (engine.DidGetPotion(player, engine.power)) {
      engine.power.SetXPosition(1000);
      engine.power.SetYPosition(1000);
      is_invincible = true;
      start_potion_time = std::chrono::high_resolution_clock::now();
    }

    cinder::gl::clear();
    DrawBackground();
    DrawTimer();
    DrawUser();
    DrawFire();
    DrawMonster();
    DrawFlashMonster();
    DrawPotion();
  }
}

void MyApp::keyDown(KeyEvent event) {
  if ((is_burned || is_caught) && is_invincible==false) {
    return;
  }
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
  if ((is_burned || is_caught) && is_invincible==false) {
    return;
  }
  auto back_texture =
            cinder::gl::Texture::create(ci::
            loadImage(loadAsset("running_ninja1.png")));
    if (ninja_counter == 2) {
        back_texture =
                cinder::gl::Texture::create(ci::loadImage
                (loadAsset("running_ninja2.png")));
    } else if (ninja_counter == 3) {
        back_texture =
                cinder::gl::Texture::create(ci::loadImage
                (loadAsset("running_ninja3.png")));
    } else if (ninja_counter == 4) {
        back_texture =
                cinder::gl::Texture::create(ci::loadImage
                (loadAsset("running_ninja4.png")));
    } else if (ninja_counter == 5) {
        back_texture =
                cinder::gl::Texture::create(ci::loadImage
                (loadAsset("running_ninja5.png")));
    } else if (ninja_counter == 6) {
        back_texture =
                cinder::gl::Texture::create(ci::loadImage
                (loadAsset("running_ninja6.png")));
    }

    if (ninja_counter < 6) {
      ninja_counter++;
    } else {
      ninja_counter = 1;
    }

  ci::gl::color(ci::ColorA(1, 1, 1, 1));
    if (is_invincible) {
      ci::gl::color(ci::ColorA(0, 0.8, 1, 90));
    }
    cinder::gl::draw(back_texture, ci::Rectf({player.GetXPosition(),
                                              player.GetYPosition()},
                                             {player.GetXPosition() + 100,
                                              player.GetYPosition() + 100}));
}

void MyApp::DrawMonster() {
  auto back_texture =
      cinder::gl::Texture::create(
          ci::loadImage(loadAsset("monster_pic.png")));
  ci::gl::color(ci::ColorA(1, 1, 1, 1));

  for (int i = 0; i < monster_vector.size(); i++) {
    monster_vector[i].MoveTowardsPlayer(player.GetXPosition(),
                                        player.GetYPosition());
    cinder::gl::draw(back_texture,
                     ci::Rectf({monster_vector[i].GetXPosition(),
                                monster_vector[i].GetYPosition()},
                               {monster_vector[i].GetXPosition() + 65,
                                monster_vector[i].GetYPosition() + 65}));
  }
}

void MyApp::DrawFlashMonster() {
  auto back_texture =
      cinder::gl::Texture::create(ci::loadImage(
          loadAsset("monster_pic.png")));
  ci::gl::color(ci::ColorA(1, 1, 1, 1));

  if (flash_wait_counter >= 20) {
    engine.flash_monster.ChangePosition();
    if (abs(player.GetXPosition() - engine.flash_monster.GetXPosition()) <= 40
           && abs(player.GetYPosition() - engine.flash_monster.GetYPosition()) <= 40) {
      engine.flash_monster.ChangePosition();
      engine.FixFlashPosition(player, engine.flash_monster);
    }
    flash_wait_counter = 0;
  }
  flash_wait_counter++;

  cinder::gl::draw(back_texture,
                   ci::Rectf({engine.flash_monster.GetXPosition(),
                              engine.flash_monster.GetYPosition()},
                             {engine.flash_monster.GetXPosition() + 65,
                              engine.flash_monster.GetYPosition() + 65}));
}



void MyApp::DrawFire() {
  auto back_texture =
      cinder::gl::Texture::create(
          ci::loadImage(
              loadAsset("fire1.png")));

  if (lava_counter == 2) {
    back_texture =
        cinder::gl::Texture::create(
            ci::loadImage(
                loadAsset("fire2.png")));
  } else if (lava_counter == 3) {
    back_texture =
        cinder::gl::Texture::create(
            ci::loadImage(
                loadAsset("fire3.png")));
  } else if (lava_counter == 4) {
    back_texture =
        cinder::gl::Texture::create(
            ci::loadImage(
                loadAsset("fire4.png")));
  } else if (lava_counter == 5) {
    back_texture =
        cinder::gl::Texture::create(
            ci::loadImage(
                loadAsset("fire5.png")));
  }

  if (lava_counter < 5) {
    lava_counter++;
  } else {
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


template <typename C>
void PrintText(const string& text, const C& color, const cinder::ivec2& size,
               const cinder::vec2& loc) {
  cinder::gl::color(color);

  auto box = TextBox()
      .alignment(TextBox::CENTER)
      .font(cinder::Font(kBoldFont, 30))
      .size(size)
      .color(color)
      .backgroundColor(
          cinder::ColorA(0, 0, 0, 0))
      .text(text);

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {loc.x - box_size.x / 2,
                             loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}

void MyApp::DrawGameOverScreen() {
  if (printed_game_over) return;

  image = cinder::gl::Texture2d::create(fire_end_img);
  cinder::Rectf drawRect( 0.0f,
                          0.0f,
                          1000.0f,
                          1000.0f);
  cinder::gl::draw(image, drawRect);


  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {800, 100};
  const cinder::Color color = cinder::Color::black();

  PrintText("YOUR SCORE: " + std::to_string(player.GetMyScore()),
      color, size, {center.x, center.y - (1) * 50});


  size_t row = 0;
  PrintText("Top Scores:", color, size,
      {center.x, center.y + 50 + ++row * 50});
  for (int i = 0; i < top_player_scores.size(); i++) {
    PrintText(top_player_names[i] + " - " +
    std::to_string(top_player_scores[i]),
              color, size, {center.x, center.y + 50 + (++row) * 50});
  }

  printed_game_over = true;
}

void MyApp::DrawBackground() {
  if (should_start_time && welcome_count > kWelcomeTime) {
    t1 = std::chrono::high_resolution_clock::now();
    should_start_time = false;
  }

  if (welcome_count <= kWelcomeTime) {
    const cinder::vec2 center = getWindowCenter();
    const cinder::ivec2 size = {800, 200};
    const cinder::Color color = cinder::Color::white();

    auto back_texture =
        cinder::gl::Texture::create(ci::
        loadImage(loadAsset("welcome_back.png")));
    ci::gl::color(ci::ColorA(1, 1, 1, 1));
    cinder::gl::draw(back_texture, ci::Rectf({0,
                                              0},
                                             {1000,
                                              1000}));
    PrintLoadingScreen();
    welcome_count++;

  } else {
    auto back_texture =
        cinder::gl::Texture::create(ci::
        loadImage(loadAsset("rock_texture.png")));
    ci::gl::color(ci::ColorA(0.8, 0.8, 1, 1));
    cinder::gl::draw(back_texture, ci::Rectf({0,
                                              0},
                                             {800,
                                              800}));
  }
}

void MyApp::DrawTimer() {
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {800, 200};
  const cinder::Color color = cinder::Color::white();
  ci::gl::color(ci::ColorA(1, 1, 1, 1));
  std::chrono::high_resolution_clock::time_point t2 =
      std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> time_span =
      duration_cast<std::chrono::duration<double>>(t2 - t1);

  int current_time = time_span.count();
  PrintText(std::to_string(current_time),
            color, size, {20, 120});
}

void MyApp::DrawPotion() {
  auto back_texture =
      cinder::gl::Texture::create(ci::loadImage(
          loadAsset("potion_img.png")));
  ci::gl::color(ci::ColorA(1, 1, 1, 1));

  cinder::gl::draw(back_texture,
                   ci::Rectf({engine.power.GetXPosition(),
                              engine.power.GetYPosition()},
                             {engine.power.GetXPosition() + 60,
                              engine.power.GetYPosition() + 45}));
}

void MyApp::PrintLoadingScreen() {
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {800, 200};
  const cinder::Color color = cinder::Color::white();

  PrintText(kWelcome, color, size,
            {center.x, center.y + (0) * 50});
  PrintText(kInstructions, color, size,
            {center.x, center.y + (1) * 50});
  PrintText(kGetReady, color, size,
            {center.x, center.y + (2) * 100});
  PrintText(kLoading, color, size,
            {center.x, center.y + (3) * 100});

  if (loading_counter == 1) {
    PrintText("...", color, size,
              {center.x + 70, center.y + (3) * 100});
    loading_counter++;
  } else if (loading_counter == 2) {
    PrintText("....", color, size,
              {center.x + 70, center.y + (3) * 100});
    loading_counter++;
  } else {
    PrintText(".....", color, size,
              {center.x + 70, center.y + (3) * 100});
    loading_counter = 1;
  }
}

}