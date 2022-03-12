#ifndef MULTI_DRAWABLE
#define MULTI_DRAWABLE
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "entity/strategies/strategy.h"

class MultiDrawable : public sf::Drawable/*a MultiDrawable can be in toDraw of another MultiDrawable*/, public virtual Strategy {
private:
    std::vector<sf::Drawable*> toDraw; //list of sprites/shapes to draw
    //!!! big question on the best way to store Sprites ? and on the pointer and freeing...
public:

    MultiDrawable() = default;
    MultiDrawable(sf::Drawable*);
    MultiDrawable(std::vector<sf::Drawable*>);

    void draw(sf::RenderTarget& target/*often the window where to draw*/, 
              sf::RenderStates states/*shader or other*/);
    
    void addSprite(sf::Drawable*);//called addSprite but can add any sf::Drawable
};

#endif
