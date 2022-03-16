#include "phx/collision.h"
#include "entity/entity.h"
#include "entity/strategies/physical_entity.h"


vel singleCheckCollision(Entity* ett1, Entity* ett2){
    Hitbox hbx = ((PhysicalEntity*)(ett1->getStrategy(PHYSICAL)))->getHitbox();
    std::vector<pos> hbx_points = hbx.getHitbox();

    unsigned int minx1 = hbx_points.at(0).x;
    unsigned int maxx1 = hbx_points.at(1).x;
    unsigned int miny1 = hbx_points.at(0).y;
    unsigned int maxy1 = hbx_points.at(1).y;
    
    hbx = ((PhysicalEntity*)(ett2->getStrategy(PHYSICAL)))->getHitbox();
    hbx_points = hbx.getHitbox();
    unsigned int minx2 = hbx_points.at(0).x;
    unsigned int maxx2 = hbx_points.at(1).x;
    unsigned int miny2 = hbx_points.at(0).y;
    unsigned int maxy2 = hbx_points.at(1).y;

    int xcol = 0;
    int ycol = 0;

    if(maxx1>minx2 && maxx2 > minx1){
        xcol = -min(maxx2 - minx1, maxx1 - minx2);
    }
    if(maxy1>miny2 && maxy2 > miny1){
        ycol = -min(maxy2 - miny1, maxy1 - miny2);
    }

    return vel(xcol, ycol);
}

vector<Collider> checkCollision(std::vector<Entity*> entities){
    int nbEtt = entities.size();
    vel tmpVect;
    Collider collider;
    vector<Collider> colliderList = vector<Collider>();
    for(int i = 0; i < nbEtt - 1; i++){
        for(int j = i+1; i < nbEtt - 1; i++){
            tmpVect = singleCheckCollision(entities.at(i), entities.at(j));
            if(tmpVect.x != 0 || tmpVect.y != 0){
                collider = Collider();
                collider.collisionVector = tmpVect;
                collider.ettColliding = entities.at(0);
                collider.ettCollided = entities.at(1);
                colliderList.push_back(collider);
            }
        }
    }
    return colliderList;
}
