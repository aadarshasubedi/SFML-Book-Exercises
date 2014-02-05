#ifndef PICKUP_HPP
#define PICKUP_HPP

#include <SFML/Graphics/Sprite.hpp>

#include "Entity.hpp"
#include "Command.hpp"
#include "ResourceIdentifiers.hpp"

class Aircraft;

class Pickup : public Entity {            
    public:
        enum Type {
            HealthRefill,
            MissileRefill,
            FireSpread,
            FireRate,
            TypeCount
        };
        
    private:
        Type mType;
        sf::Sprite mSprite;

    public:
        Pickup(Type type, const TextureHolder& textures);

        virtual unsigned int getCategory() const;
        virtual sf::FloatRect getBoundingRect() const;

        void  apply(Aircraft& player) const;

    protected:
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // PICKUP_HPP