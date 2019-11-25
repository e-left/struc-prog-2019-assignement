# Assignement for the Structured Programming class, 2019
---
This is an implementation of the classic Score 4 game, with a small twist. The game ends when the board is filled or when one of the players inputs an invalid move, in which case they immediately lose. When the board is filled, each player's score is the maximum number of "chips" he has on any direction(horizontally, vertically or diagonally). If the players have the same score then the overall number of their "chips" sequentially is counted and then the player with the
highhighest score wins. 

Current implementation allows two players to play but it can be easily adapted to allow three or more players(maximum 9) to play together, by modifying the `main.c` file.

# Structure
---
- The C files `board.c` and `board.h` contain the `Board` structure and the helper functions needed for the game to work properly. These files are **not** to be changed if you plan on trying the assignement.

- The c file `main.c` contains the game logic and handles the board printing in between rounds. The only change you are supposed to make if you intend to try the assignement would be to add the new player functions(note below).

- The c files `player_X.c` and `player_X.h` are created by you and you are supposed to implement your player logic there.

The `Board` struct is defined as follows:

- `int rows`: The number of rows in the board.
- `int columns`: The number of columns in the board.
- `int** Board`: Two dimensional array, sized `[rows][columns]`, containing 0 in every free spot and either 1 or 2 to represent each player's "chips".

# How to play
---
In order to create a player, you should copy the `player_X.c` and `player_X.h` files, replacing the X with your team's numbers. E.g.: `player_9898_3839.c` and `player_9898_3839.h`.

The existing c file `player_random.c` (along with it's header `player_random.h` implement a player that choses a random valid move in every turn.

After you have created your logic you go to the file `main.c` and you perform the following changes(suppose you want to change the random player):

1. Replace the header file `player_random.h` with the one you created.
2. Replace the function `player_random` in line 15 or 16 with your function name that you implemented in your file.

Apart from that you have to write a 5 page report, explaining and presenting your algorithm.

# How to win
---
Your objective is to implement your function in your file correctly to create a "smart" player that will be able to win the random player effectively. As a stepup in the end of the semester two players will be pitted agains each other to see which one works the best. Alas, your objective is to create a strategy to beat this game.

# Instructions
---
The game has been developed and tested in a linux environment. You can clone this repo to get the code, or you can download a zip archive of this repository.

## Requirements

You should have `ggc` installed, or an equivalent compiler. In order to properly complile the assignement after you have created your functions you can do the following:
1. `cd <project-folder>`
2. `gcc *.c -o prog`
3. `./prog` 

If it compiles without errors(if your code is correct), on startup the game will prompt you for some input:
- Board size: given in: M N
- Delay between each move. Accepted inputs are:
    - A positive float, which will be the delay in seconds.
    - 0, to have no delay in between rounds.
    - -1, to be able to step over each move when you press `Enter`

# Grading
---
- You can get a maximum of +2 each for a perfect implementation of a player. Meaning that you have to create a good working algorithm and have a good report and presentation when you hand your assignement.
- In the end of the semester a knockout type contest will be held:
    - First team gets +1 extra grade
    - Second team gets +0.5 extra grade
    - Third team gets +0.25 extra grade


