#include "multi_drawable.h"

void MultiDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) {
    for(sf::Drawable* d : toDraw){
        target.draw(*d,states);
    }
}

void MultiDrawable::MultiDrawable(std::vector<sf::Drawable*> &spriteVector){
    this->toDraw.swap();//normally free the vector, but don't free the sprites where pointers in it point to
    this->toDraw = spriteVector;
}

void MultiDrawable::MultiDrawable(sf::Drawable *sprite){
    this->addSprite(sprite);
}

void MultiDrawable(){
    //would it be good by default to add a "default sprite" to avoid risk of crashed when draw on empty vector
}
void ~MultiDrawable(){

}