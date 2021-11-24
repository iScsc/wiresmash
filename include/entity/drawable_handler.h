#ifndef DRAWABLE_HANDLER
#define DRAWABLE_HANDLER

#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class DrawableHandler : public sf::Drawable {
private:
    std::vector<sf::Drawable*> toDraw;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        for(sf::Drawable* d : toDraw){
            target.draw(*d,states);
        }
    }
public:
    DrawableHandler();
    ~DrawableHandler();
};



DrawableHandler::DrawableHandler(/* args */){
}

DrawableHandler::~DrawableHandler(){
}


#endif