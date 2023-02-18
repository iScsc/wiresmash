# Wiresmash

Wiresmash is a Smash-like game currently under development by the iScsc dev team.

## Currently

The game is currently a very simple demo containing:

- simple physics system: gravity, collisions
- simple graphic system: shapes using SFML
- simple box system: only rectangles, used only for collisions so far
- simple input system, with keybindings read from a file

It consists of two red squares and a blue platform. The squares are controllable using (by default) the keys WASD/IJKL for up/left/down/right and Space/M for "jump".

## Next Step

- A simple combat prototype
- Better jump system
- Real kinematics system with management of velocity, more forces, ...

## Launching

Make sure to launch the executable from the `./bin` folder, or it will not find the keybinds and scream an error.

## Build

### Requirements

- a `C++` compiler of your choice
- `CMake`
- `SFML`

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

> **Note**
> you can directly use the `build`, `run` and `clean` rules for `make` instead
> ```bash
> make build run
> ```
> to run the application and
> ```bash
> make clean
> ```
> to clean all compilation files
