#include "entity/strategies/multi_drawable.h"

void MultiDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) {
    for(sf::Drawable* d : toDraw){
        target.draw(*d,states);
    }
}

MultiDrawable::MultiDrawable(std::vector<sf::Drawable*> spriteVector){
    this->toDraw.clear();//normally free the vector, but don't free the sprites where pointers in it point to
    this->toDraw = spriteVector;
}

MultiDrawable::MultiDrawable(sf::Drawable *sprite){
    this->addSprite(sprite);
}
