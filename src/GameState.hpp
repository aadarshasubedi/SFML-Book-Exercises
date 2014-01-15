#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "World.hpp"
#include "Player.hpp"

class GameState : public State {

    private:
        World mWorld;
        Player&	mPlayer;
        
    public:
        GameState(StateStack& stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);
};

#endif // GAMESTATE_HPP