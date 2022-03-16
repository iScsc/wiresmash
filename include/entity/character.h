#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>

#include "entity/entity.h"
#include "entity/strategies/strategy.h"
#include "entity/strategies/multi_drawable.h"
#include "entity/strategies/controllable.h"
#include "entity/strategies/physical_entity.h"
#include "entity/strategies/schedulable.h"
#include "entity/strategies/damageable.h"

class Character : public Entity {
private:

    std::vector<Hitbox> attackHitbox; //in a strategy ?
    Hitbox damageHitbox;  //-->> in the future stored in strategies ???

    static std::vector<Strategy*> generateDefaultStrategies();

    float strength;
    float maxSpeed;
    float jumpHeight;

public:

    void addAttackHitbox(Hitbox htbx);

    void eraseAttackHitbox(int index);

    void eraseAttackHitbox(int indexFirst, int indexLast);

    std::vector<Hitbox> &getAttackHitbox();

    Hitbox &getDamageHitbox();

    void setDamageHitbox(Hitbox &damageHitbox);

    float getStrength();

    void setStrength(float strength);

    float getMaxSpeed();

    void setMaxSpeed(float maxSpeed);

    float getJumpHeight();

    void setJumpHeight(float jumpHeight);


public:

    Character();
    Character(std::vector<Strategy*> strategies); //or every player has the same strategies ? to be discussed...
    Character(float strength, float maxSpeed, float jumpHeight);
    Character(std::vector<Strategy*>, float strength, float maxSpeed, float jumpHeight);
    ~Character();

};

#endif
