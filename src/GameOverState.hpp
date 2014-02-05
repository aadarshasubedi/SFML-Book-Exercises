#ifndef GAMEOVERSTATE_HPP
#define GAMEOVERSTATE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Container.hpp"

class GameOverState : public State {
    private:
        sf::Text mGameOverText;
        sf::Time mElapsedTime;
        
    public:
        GameOverState(StateStack& stack, Context context, const std::string& text);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);
};

#endif // GAMEOVERSTATE_HPP
