#ifndef LIB_H
#define LIB_H

#include <tuple>

typedef std::pair<unsigned int, unsigned int> Vec;
typedef std::pair<int, int> Vel;

typedef struct phxParam
{   
    Vec position;
    Vel velocity;
} phxParam;

enum Force {weight};

#endif
