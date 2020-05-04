//
// Created by Ansh Bhalla on 5/2/20.
//

#ifndef FINALPROJECT_ENGINE_H
#define FINALPROJECT_ENGINE_H
#include <vector>
#include <cstdlib>

#include "mylibrary/monster.h"
#include "mylibrary/player.h"
#include "mylibrary/flashmonster.h"

#endif  // FINALPROJECT_ENGINE_H

class Engine {

 public:
  /**
   * Checks the positions of the monsters, flash monster, and the player to
   * see if the player came in contact with any of the monsters;
   * @param current_player - the player the user is controlling
   * @param monster_vector - a vector with all the monsters
   * @param flash_monster - the flash monster
   * @return - true if the player was caught, otherwise false
   */
  bool CheckIfCaught(Player current_player,
      std::vector<Monster> monster_vector, FlashMonster flash_monster);

  /**
   * Checks the positions of the fires and the player to
   * see if the player came in contact with any of the fire;
   * @param current_player - the player the user is controlling
   * @param pieces - the positions of the fires
   * @return - true if the player was bruned, otherwise false
   */
  bool CheckIfBurned(Player current_player, std::vector<Board> pieces);

  /**
   * Changes the position of the flash monster if it generates a position
   * that is at the same position of the player
   * @param current_player - the player to compare the position to
   * @param flash_monster - the current flash monster
   */
  void FixFlashPosition(Player current_player, FlashMonster flash_monster);

};