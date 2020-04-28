# Escape

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)

Read [this document](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html) to understand the project
layout.

Author: [Ansh Bhalla]

---
Escape is a game that will involve the main character, which the
user will be controlling, and enemy monsters that will be
chasing the main player. The goal of the game is for the player
to stay alive without coming in contact with a monster
or the lava blocks. After the welcome screen, that describes
the instructions, the player must maneuver around the walls to
remain alive for the longest time possible. If the monster and player 
come in contact with each other, then the player will lose the game.
I want to do this project as I believe this game would be pretty
interesting to create. Since there will be an actual person
playing the game, it appeals to me and others who are interested
in different video games. Also, I will be able to come back
to this game later on, and possibly even improve it more with
new skills I learn in the future.

The library I plan on using is the SQL library. With this library,
I can keep track of the scores of all players that have played this 
game. This way, I can create a leaderboard in the game over screen.

One library that I plan on using is called frozen. With this
library, I will be able to keep track of the scores of different
players in a JSON file and access this JSON when creating a
leaderboard. Another library I plan to use is Cimg. With this
library, I can load the images to use when creating the player
and monster characters.
https://github.com/cesanta/frozen , 
http://cimg.eu/

By the End of Week 1, I plan on having the welcome screen
with instructions completed, along with completing the player's
movement with the arrow keys. By the End of Week 2, I would
like to complete creating the monsters and having them chase the
player, along with creating a board for the game. By the end of
Week 3, I plan on implementing saving the scores and having the 
user enter an image to be used as their character.

If I were to finish the project early, one stretch goal that
I would try to implement would be trying to have the user
input a text file. Using that text file, a new board could be
made, otherwise, it can use the default board. Another stretch goal
would be trying to use the live camera, capture an image, and
use that image as the monster characters.