#ifndef TITLESTATE_HPP
#define TITLESTATE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "State.hpp"

class TitleState : public State {
    private:
        sf::Sprite mBackgroundSprite;
        sf::Text mText;

        bool mShowText;
        sf::Time mTextEffectTime;
        
    public:
        TitleState(StateStack& stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);
};

#endif // TITLESTATE_HPP
