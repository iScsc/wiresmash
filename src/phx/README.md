#PHX

- Use unsigned int from 0 to MAX_INT to calculate the physics
- Positions are unsigned int pairs, Vectors are signed int pairs. These types are declared in lib.
- updateCinematics act like the pfd. Do not take into account collisions.
  Param: PhysicalEntity
  Output: correction velocity to apply
