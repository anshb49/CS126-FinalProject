//
// Created by Ansh Bhalla on 5/2/20.
//

#include "mylibrary/engine.h"

bool Engine::CheckIfCaught(Player current_player, std::vector<Monster> monster_vector, FlashMonster flash_monster) {
  for (int i = 0; i < monster_vector.size(); i++) {
    if (abs(current_player.GetXPosition() - monster_vector[i].GetXPosition()) <= 50
        && abs(current_player.GetYPosition() - monster_vector[i].GetYPosition()) <= 50) {
      return true;
    }
  }

  if (abs(current_player.GetXPosition() - flash_monster.GetXPosition()) <= 40
      && abs(current_player.GetYPosition() - flash_monster.GetYPosition()) <= 40) {
    return true;
  }
  return false;
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
