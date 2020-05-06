//
// Created by Ansh Bhalla on 5/2/20.
//

#ifndef FINALPROJECT_ENGINE_H
#define FINALPROJECT_ENGINE_H
#include <vector>
#include <cstdlib>
#include <string>

#include "mylibrary/monster.h"
#include "mylibrary/player.h"
#include "mylibrary/flashmonster.h"
#include "mylibrary/invincible_power.h"


#endif  // FINALPROJECT_ENGINE_H

class Engine {
 private:
  const int kNumFireEasy = 14;
  const int kNumFireMedium = 20;
  const int kNumFireHard = 26;


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

  /**
   * Based on what the user inputted, returns the number of positions of the fire
   * to be displayed as that is what differs between levels.
   * @param level - the input level through program arguments
   * @return - a number based on the constants that match the game level. If it is
   * invalid, returns the easy constant value.
   */
  int DecideGameLevel(int level);

  /**
   * Based on the player location and the potion location, checks if the player
   * came in contact with the potion.
   * @param player - the current player in the game
   * @param power - the potion that stores location
   * @return - true if the player picked up the potion, otherwise false
   */
  bool DidGetPotion(Player player, InvinciblePower power);

  InvinciblePower power;
  Monster monster;
  FlashMonster flash_monster;
};