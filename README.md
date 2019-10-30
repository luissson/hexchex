# Welcome to HexChex Chinese Checkers

The goal of this project is to make the classic game Chinese Checkers,
also known as Sternhalma.

Planned features:
- Graphical and commandline interfaces
- Single player vs. AI players
- Hotseat multiplayer
- Network (LAN) multiplayer
- Scripting support for adding new AI players


## Build Instructions

    mkdir build
    cd build
    cmake .. && make


## Running tests

To run all tests with short summary:

    make test

To see longer gtest output and test failures:

    make check


## Contributing

Refer to the contributing guildlines in CONTRIBUTING.md.


## Design notes

### Board and coordinates

Chinese checkers is played on a haxagonal grid.  To simplify rules
checking, HexChex uses cube coordinates.  Axial coordinates are used
to display and take user input for the commandline interface.  See
https://www.redblobgames.com/grids/hexagons/ for more information on
hexagonal grids.

The `Board` class stores the current state of the board: what color
piece is in each location.

## Players

Players can be local human players (single player or hotseat using
local mouse/keyboard input), network players, or local AI computer
players.  Each player class should output a series of moves and
receive updates as a series of moves for each player.

## Game state

The `Game` class is responsible for coordinating all the players in a
game, handling turns in order, passing moves to the Core, and keeping
score.

## Core rules

The `Core` class is responsible for all the rules of the game.  Moves
are checked for legality against the state stored in Board.  The Core
class also checks whether any player has won.


```
  +-----------+
  |           |
  |  UI /     |
  |  Display  |<------------------get board state--------------------+
  |           |                                                      |
  +-----------+                                                      |
        |                                                            |
        |                                                            |
  +-----------+                                                  +------------+
  |           |                                                  |
  |  Hotseat  |<---moves,turn,win, score----+                    |   Board    |
  |  Player   |---------moves----------->+  |                    |            |
  |           |-----new game--------->+  |  |                    |            |
  +-----------+                       |  |  |                    +------------+
                                      |  |  |                      |       ^
                                      |  |  |                      |       |
                                      |  |  |                    read   update
                                      |  |  |                      |       |
                                      v  v  |                      v       |
  +-----------+                   +-----------+                  +------------+
  |           |                   |           |                  |            |
  |  AI       |<-----create-------|   Game    |-------moves----->|    Core    |
  |  Player   |---------moves---->|           |<----check win----|    Rules   |
  |           |<-----moves,win----|           |                  |            |
  +-----------+                   +-----------+                  +------------+
                                    ^ |   |
                                    | |   |
  +-----------+                     | |   |
  |  Network  |---------connect-----+ |   |
  |  Player   |-----moves-------------+   |
  |           |<---------sendmoves--------+
  +-----------+
```