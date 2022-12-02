#include "engine/physic/phxbox.h"

void PhxBox::setCollisionType(CollisionBehaviour ct){
    this->type = ct;
}

void PhxBox::linkOwner(Entity* owner){
    this->owner = owner;
}

void PhxBox::linkBox(Box<PhxBox>* box){
    this->box = box;
    box->linkOwner(this);
    box->linkPos(this->owner_pos);
}

void PhxBox::solveCollision(Collision<PhxBox>& coll_pb){
    PhxBox* that = coll_pb.collided;
    if (that->type == CollisionBehaviour::STATIC){
        //internal logic with full amplitude for displacement
        coll_pb.collisionVector.first *= 2;
        coll_pb.collisionVector.second *= 2;
    }
    //internal logic
    switch (type)
    {
    case CollisionBehaviour::PUSHABLE:
        if(coll_pb.collisionVector.second == 1) {coll_pb.collisionVector.second = 2;}
        if(coll_pb.collisionVector.first == 1) {coll_pb.collisionVector.first=2;}
        
        if(abs(coll_pb.collisionVector.first) > abs(coll_pb.collisionVector.second)){
            owner_pos->second -= (coll_pb.collisionVector.second)/2;
        }else if(abs(coll_pb.collisionVector.first) < abs(coll_pb.collisionVector.second)){
            owner_pos->first -= (coll_pb.collisionVector.first)/2;
        } else {
            owner_pos->first -= (coll_pb.collisionVector.first)/2;
            owner_pos->second -= (coll_pb.collisionVector.second)/2;
        }
    case CollisionBehaviour::STATIC:
        //do nothing
        break;
    default:
        break;
    }
    coll_pb.colliding = that;
    coll_pb.collided = this;
    coll_pb.collisionVector.first *= -1;
    coll_pb.collisionVector.second *= -1;

}

void PhxBox::linkPos(std::pair<double, double>* owner_pos){
    this->owner_pos = owner_pos;
}

void PhxBox::linkVel(std::pair<double, double>* owner_vel){
    this->owner_vel = owner_vel;
}

Entity* PhxBox::getOwner(){
    return this->owner;
}