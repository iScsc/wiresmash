#include "multi_drawable.h"

void MultiDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) {
    for(sf::Drawable* d : toDraw){
        target.draw(*d,states);
    }
}

void MultiDrawable::addSprite(sf::Drawable *sprite){//is pointer adn referencing right ? are there memory leaks ?
    this->toDraw.push_back(sprite);
}

void MultiDrawable::MultiDrawable(std::vector<sf::Drawable*> &spriteVector){
    this->toDraw.swap();
    this->toDraw = spriteVector;
}

void MultiDrawable::MultiDrawable(sf::Drawable *sprite){
    this->addSprite(sprite);
}

void MultiDrawable(){

}
void ~MultiDrawable(){

}