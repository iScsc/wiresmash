/**
 * @file input_reader.h
 * @author Grégory Brivady
 * @brief Read keybinds from a file
 * @version 0.1
 * @date 2022-12-04
 * 
 * 
 */
#ifndef SETTINGS_INPUT_READER_H
#define SETTINGS_INPUT_READER_H

#include <list>
#include <string>
#include <iostream>
#include <fstream>

#include <SFML/Window/Keyboard.hpp>
#include "engine/input/input_handler.h"

/**
 * @brief make a list of keybinds, given a file
 * 
 * @param path input file
 * @return std::list<Keybind> 
 */
std::list<Engine::Keybind> make_keybinds(std::string path);

/**
 * @brief Read the players part of the inputs
 * 
 * @param keybinds 
 * @param file 
 */
void read_player_input(std::list<Engine::Keybind>& keybinds, std::ifstream& file);

/**
 * @brief Transforms a string to an sfml key
 * 
 * @param str 
 * @return sf::Keyboard::Key 
 */
sf::Keyboard::Key key_of_string(std::string str);

#endif