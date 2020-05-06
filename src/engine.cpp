//
// Created by Ansh Bhalla on 5/2/20.
//
#include <iostream>
#include "mylibrary/engine.h"



bool Engine::CheckIfCaught(Player current_player, std::vector<Monster> monster_vector, FlashMonster flash_monster) {
  for (int i = 0; i < monster_vector.size(); i++) {
    if (abs(current_player.GetXPosition() - monster_vector[i].GetXPosition()) <= 30
        && abs(current_player.GetYPosition() - monster_vector[i].GetYPosition()) <= 50) {
      return true;
    }
  }

  bool is_touching_flash = (abs(
      current_player.GetXPosition() - flash_monster.GetXPosition()) <= 40
          && abs(current_player.GetYPosition()
          - flash_monster.GetYPosition()) <= 40);
  return is_touching_flash;
}


bool Engine::CheckIfBurned(Player current_player, std::vector<Board> pieces) {
  for (int i = 0; i < pieces.size(); i++) {
    if (current_player.GetXPosition() >= pieces[i].GetXPos() - 50.0
        && current_player.GetXPosition() <= pieces[i].GetXPos() + 30.0
        && current_player.GetYPosition() >= pieces[i].GetYPos() - 60.0
        && current_player.GetYPosition() <= pieces[i].GetYPos() + 40.0) {
      return true;
    }
  }
  return false;
}

void Engine::FixFlashPosition(Player current_player, FlashMonster flash_monster) {
  while (abs(current_player.GetXPosition() - flash_monster.GetXPosition()) <= 40
      && abs(current_player.GetYPosition() - flash_monster.GetYPosition()) <= 40) {
    flash_monster.ChangePosition();
  }
}

int Engine::DecideGameLevel(int game_level) {
  bool is_invalid_level = game_level != 1 && game_level != 2 && game_level != 3;
  if (is_invalid_level || game_level == 1) {
    return kNumFireEasy;
  } else if (game_level == 2) {
    return kNumFireMedium;
  } else {
    return kNumFireHard;
  }
}

bool Engine::DidGetPotion(Player player, InvinciblePower power) {

  if (abs(player.GetXPosition() - power.GetXPosition()) <= 40 && abs(player.GetYPosition() - power.GetYPosition()) <= 40) {
    return true;
  }
}
