# Tactics

A turn-based tactical RPG in C++17 and SFML 3. Grid-based combat with
pathfinding, a small squad per side, and an AI opponent.

Started as an excuse to build a proper A* implementation and a turn system
from scratch on top of my own math types, rather than leaning on an engine.

## Status

Early. Window opens and the Vec2 math class is in place. Grid and pathfinding
are next.

## Requirements

- CMake 3.16
- A C++17 compiler (clang++ or g++)
- SFML 3

## Build

```sh
cmake -S . -B build
cmake --build build
```

## Run

```sh
./build/Tactics
```

## Layout

```text
Tactics/
├── assets/
├── src/
│   └── math/
├── tests/
├── .clang-format
├── .gitignore
├── CMakeLists.txt
└── README.md
```

Directories and files use snake_case, types use PascalCase. Formatting is
handled by `clang-format` with the config in `.clang-format`.

## Roadmap

- [ ] Grid class
- [ ] A* pathfinding, with tests
- [ ] Grid and unit rendering
- [ ] Combat and damage
- [ ] Enemy AI
- [ ] Turn state machine
- [ ] Win/lose conditions and restart

