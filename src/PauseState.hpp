#ifndef PAUSESTATE_HPP
#define PAUSESTATE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Container.hpp"

class PauseState : public State {
    private:
        sf::Sprite mBackgroundSprite;
        sf::Text mPausedText;
        GUI::Container mGUIContainer;
        bool mLetUpdatesThrough;

    public:
        PauseState(StateStack& stack, Context context, bool letUpdatesThrough = false);
        ~PauseState();

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);
};

#endif // PAUSESTATE_HPP