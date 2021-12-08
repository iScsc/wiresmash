#ifndef DRAWABLE_HANDLER
#define DRAWABLE_HANDLER
#include "strategy.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class MultiDrawable : public sf::Drawable/*--> peut etre le mettre en attribut*/, public virtual Strategy {
private:
    std::Vector<sf::Drawable*> toDraw; //list of sprites/shapes to draw
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states); //i don't understand why const, comes form google "sfml drawable"

public:
    DrawableHandler();
    ~DrawableHandler();
};

// in cpp:

virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(sf::Drawable* d : toDraw){
        target.draw(*d,states);
    }
}

DrawableHandler::DrawableHandler(/* args */){
}

DrawableHandler::~DrawableHandler(){
}


#endif