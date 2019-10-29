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