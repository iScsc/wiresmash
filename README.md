# Wiresmash <!-- omit in toc -->

Wiresmash is a Smash-like game currently under development by the iScsc dev team.

## Table of content <!-- omit in toc -->

- [Useful links](#useful-links)
- [Current Features](#current-features)
- [Launching](#launching)
- [Building from source](#building-from-source)
  - [Requirements](#requirements)
  - [Building with CMake](#building-with-cmake)
- [Future Plans](#future-plans)

## Useful links

- [The iscsc website](https://iscsc.fr/)
- [How to contribute](CONTRIBUTING.md)
- [Wiresmash wiki](https://github.com/iScsc/wiresmash/wiki)

## Current Features

The game is currently a very simple demo containing:

- simple physics system: gravity, collisions
- simple graphic system: shapes using SFML
- simple box system: only rectangles, used only for collisions so far
- simple input system, with keybindings read from a file

It consists of two red squares and a blue platform. The squares are controllable using (by default) the keys WASD/IJKL for up/left/down/right and Space/M for "jump".

## Launching

Make sure to launch the executable from the `./bin` folder, or it will not find the keybinds and scream an error.

## Building from source

### Requirements

- `C++` compiler supporting `C++17` or newer, may work with an earlier standard
- `CMake 3.16+`
- `SFML 2.5.1+`

### Building with CMake

Clone the project using `git`, then run the following commands:

```bash
cmake -S ./ -B ./build/
```

to generate a build system, then run:

```bash
cmake --build ./build/
```

to build the executable. You will find the build executable in the `./bin` folder.

## Future Plans

- A simple combat prototype with attacks and HP bars
- Better jump system
- Real kinematics system with management of velocity, more forces, ...
- Actual graphics subsystem
- Proper input configuration
