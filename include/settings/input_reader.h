#ifndef SETTINGS_INPUT_READER_H
#define SETTINGS_INPUT_READER_H

#include <list>
#include <string>
#include <iostream>
#include <fstream>

#include <SFML/Window/Keyboard.hpp>
#include "engine/input/input_handler.h"

struct Keybind //TODO : move this to input reader
{
    sf::Keyboard::Key key;
    UniversalInput    action;
};

std::list<Keybind> make_keybinds(std::string path);

void read_player_input(std::list<Keybind>& keybinds, std::ifstream& file);

sf::Keyboard::Key key_of_string(std::string str);

#endif