#ifndef PHX_PHX_H
#define PHX_PHX_H

#include <tuple>
#include <vector>

// Constrain
// vitessePersoMax < longeurPersoMin

// dependencies
class Scene;
class Entity;

typedef std::pair<unsigned int, unsigned int> Vec;
typedef std::pair<int, int> Vel;

/** 
 * Update each Entity in the Scene
 */
void update(Scene);

void updateCinematics(Entity&);
void updateCollision(Scene);

class Cinematics {
private:
    Vec m_pos;
    Vel m_vel;
};

class Hitbox {
private:
    std::vector<Vec> m_vertices;
};

class PhysicalParameters {
private:
    std::vector<int> m_parameters;
};

#endif
