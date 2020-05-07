# Escape

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)


Author: [Ansh Bhalla]

---
![image](assets/game_gif.gif)

**How To Play**
-
- Use the arrow keys to control the player after you get 
- Any contact with the monsters will or fire will cause you to lose the game
- There is a shield potion that makes you invincible for a certain amount of time 
- After you come in contact with the fire or monster, the game ends
![image](assets/gameEND.png)

**Dependencies**
-
- [SQLite](https://github.com/SqliteModernCpp/sqlite_modern_cpp/tree/dev)
  - This is used to create a leaderboard for the game and keep track
  of each player's score, along with displaying the top scores.
- [GFlags](https://github.com/gflags/gflags)
  - Used to take in the player's name and desired level using
  the program arguments
 
**How To Setup**  
-
- Download Cinder
- Extract that downloaded file into a seperate folder
- Open this folder in CLion
- Click the green run (play button) button 
at the top right part of the screen
    - Doing this will build libcinder, and this process only
    has to be done once
- Create a directory, calling it another name such as 
my-projects in the downloaded cinder file
- Clone this project into this folder

**MacOS Users**
-
- There is a change you may encounter an error of:
   `Error running 'cinder-snake': Cannot run program … cinder-snake.app/Contents/Resources"): error=13, Permission denied`
- In this case, Edit configurations -> Executable -> Select Other -> 
Find my-projects/my-app/cmake-build-debug/Debug/cinder-myapp/Contents/MacOS/cinder-myapp And click run once again.

**Gflags Arguments**
-
- These are the program arguments to enter your name, and even change the level
- To do this, go to, Edit configurations -> Program Arguments and enter (for example):
    - "--name=Bob" "--level=1"
- Level 1 represents Easy, Level 2 represents Medium, and Level 3 represents Hard


**Controls**
-
Keyboard

| Key | Action |
| ---------------|----------------|
|Left Arrow Key |Move to the Left|
|Right Arrow Key |Move to the Right|
|Up Arrow Key   |Move Up|
|Left Arrow Key |Move Down|


