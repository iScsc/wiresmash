/**
 * @file cinematic.h
 * @author Grégory Brivady
 * @brief Contains anything that may be useful to do point cinematic for the physic
 * @version 0.1
 * @date 2022-12-03
 * 
 */
#ifndef ENGINE_PHYSICS_CINEMATIC_H
#define ENGINE_PHYSICS_CINEMATIC_H

#include <vector>

#define PHX_CST_G -1

/**
 * @brief Gravity.
 * 
 * @param vel 
 * @param mass 
 */
void gravity(std::pair<double, double>* vel, double* mass);

#endif
