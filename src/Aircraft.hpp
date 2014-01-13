#ifndef AIRCRAFT_HPP
#define AIRCRAFT_HPP

#include <SFML/Graphics/Sprite.hpp>

#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"

class Aircraft : public Entity {
    public:
        enum Type {
            Eagle,
            Raptor,
        };
    
    private:
        Type mType;
        sf::Sprite mSprite;
        
    public:
        Aircraft(Type type, const TextureHolder& textures);
        virtual unsigned int getCategory() const;

    private:
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // BOOK_AIRCRAFT_HPP
