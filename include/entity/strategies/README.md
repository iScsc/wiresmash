Interfaces:

```
(1) Events Cond/Ett: void flush(unsigned short [NB_KEYS])
(2) Collisions Cond/PhX : std::vector<collisioner> checkCollision(std::vector<Entity>)
(3) Pos Update Cond/Ett : 
```

RQ sur (2):
le cond envoie TOUT, la phX teste si les hitbox "toucheur" collisionnent les "touchable"
struct collisionner:
    toucheur
    touché
    vector d'intrication