#include "engine/physics/phxbox.h"

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

void PhxBox::solveCollision(Intersection<PhxBox>& coll_pb){
    PhxBox* that = coll_pb.intersected;
    //internal logic
    switch (type)
    {
    case CollisionBehaviour::PUSHABLE:
        if (that->type == CollisionBehaviour::STATIC){
            //internal logic with full amplitude for displacement
            coll_pb.intersectionVector.first *= 2;
            coll_pb.intersectionVector.second *= 2;
        }
        if(abs(coll_pb.intersectionVector.first) > abs(coll_pb.intersectionVector.second)){
            owner_pos->second -= (coll_pb.intersectionVector.second)/2;
        }else if(abs(coll_pb.intersectionVector.first) < abs(coll_pb.intersectionVector.second)){
            owner_pos->first -= (coll_pb.intersectionVector.first)/2;
        } else {
            owner_pos->first -= (coll_pb.intersectionVector.first)/2;
            owner_pos->second -= (coll_pb.intersectionVector.second)/2;
        }
    case CollisionBehaviour::STATIC:
        //do nothing
        break;
    default:
        break;
    }
    coll_pb.intersecting = that;
    coll_pb.intersected = this;
    coll_pb.intersectionVector.first *= -1;
    coll_pb.intersectionVector.second *= -1;
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