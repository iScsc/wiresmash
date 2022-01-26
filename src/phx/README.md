# PHX README
## PHX/PFD

- Use unsigned int from 0 to MAX_INT to calculate the physics
- Positions are unsigned int pairs, Vectors are signed int pairs. These types are declared in lib.
- updateCinematics act like the pfd. Do not take into account collisions.
  Param: PhysicalEntity
  Output: correction velocity to apply

## PHX/HITBOX

2 coordinate conventions :

ETT one : (0, 0) in the top left, (x, y) with x increasing rightwards and y increasing downwards; used to define Hitbox points (a hitbox is declared by ETT team)

phx one : (0, 0) in the top left, (x, y) with x increasing rightwards and y increasing topwards ; used to return Hitbox points (a hitbox is read by phx team)

/--------------------here's the constructor : ( ETT convention )

`Hitbox(unsigned int H[][2], unsigned int size = 2)`
  - `size` is the number of points that the hitbox is made of, by default 2 (by default hitbox are rectangles), for now 2 is the only value allowed (however setting another value will save this value even if there will still be 2 points)

  - `H[][2]` is a classic array of 2-values arrays (however giving more than two 2-values arrays will just save the first two), the first should be the top left point and the second should be the bottom right point

  [ in the future, if size is allowed to change, which point you give in first is up to you but other points should be given in the same order as the shape you want create turning in the trigonometric direction, size = 1 could be used for conics like that : (a, b) with the following cononical equation (x/a)² + (y/b)² = 1 ]

  - no argument --> create a hitbox of two points (0, 0)


`void setPoint(unsigned int i, unsigned int x, unsigned int y)`
  - replace the point with index i in the hitbox by the point (x, y)


/--------------------here's how to get an information about the hitbox : ( phx convention )

`unsigned int size()`
  - give you the `size` variable explained previously, so even if for now, a hitbox is made of 2 points, if this variable is defined with another value, you will see this other value.

  [ recommended to use this fonction to make testes before using a hitbox if you're not sure hitbox will be limited to 2 points ]


`std::vector<pos> getHitbox()`
  - (pos is a pair tuple of unsigned int) this function returns all the points composing the hitbox, but the given points are the bottom left point in first and the top right in second
  
  [ if size can change and is different of 2, it only gives the points in the same order and without modification as they were define ]

## PHX/COLLISION

**DISCLAIMER:**
 Maybe we'll have to change the return type of `checkCollision` to `std::vector<Collider*>` to avoid struct duplication or side effect.. To be seen...

 
Conductor must call :  
```std::vector<Collider> checkCollision(std::vector<Entity*>);``` 
with a vector of all the entities **THAT REQUIRES COLLISION** testing. 
Meaning: there is a pre-triage to fill `checkCollision` with `Entity*` that have the `PhysicalEntity` strategy.

Returns a vector of colliders for each couple of entities that collide, so its size is upto n(n+1)/2 where n is the number of entities filled.

Collider : struct with 3 fields.
 - ettColliding     : the 1st Entity that collides into
 - ettCollided      : the Entity inside which it collides
 - collisionVector  : the vector of how much ettColliding is inside ettCollided. **see `lib/lib.h`**

EXAMPLE : 

Consider two square hitboxes, whose bottom-left & top-right corners are :
1st Square : (0, 0) -> (3, 3)
2nd Square : (2, 1) -> (5, 4)

The returned collider will be `{1st Square, 2nd Square, (+1, +2)}`

