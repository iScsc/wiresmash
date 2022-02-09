# Entity

## Collision correction

### Features to remove/check

- The whole `PhysicsProp` thing is invented by me to have the code to make sense, so something equivalent must already exist, so replace it by the adequate thing. <br>
So the `PhysicalEntity::void invertSpeed()` method may be to change, I think the behavior is understadable enough. <br>
 - The `Collisionner` structure must also be removed since it must be implemented somewhere in the physics branch.

### What does it implement ?

The main goal is to replace correctly the entities after they interpenetrated themselves. <br>
So the main feature is the `correctionUpdate` method, it takes a list of `Collisionner` (the structure is defined in the code), and corrects the positions and velocity of the entities involved in each collision.<br>
The method is `void` so it just modifies the entities via pointers.
