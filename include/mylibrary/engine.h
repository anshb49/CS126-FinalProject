//
// Created by Ansh Bhalla on 5/2/20.
//

#ifndef FINALPROJECT_ENGINE_H
#define FINALPROJECT_ENGINE_H
#include <vector>

#include "mylibrary/monster.h"
#include "mylibrary/player.h"
#include "mylibrary/flashmonster.h"

#endif  // FINALPROJECT_ENGINE_H

class Engine {

 public:
  bool CheckIfCaught(Player current_player,
      std::vector<Monster> monster_vector, FlashMonster flash_monster);
  bool CheckIfBurned(Player current_player, std::vector<Board> pieces);

};