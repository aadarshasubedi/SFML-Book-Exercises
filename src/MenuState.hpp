#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "State.hpp"

class MenuState : public State {

    private:
        enum OptionNames  {
            Play,
            Exit,
        };
        
    private:
        sf::Sprite mBackgroundSprite;

        std::vector<sf::Text> mOptions;
        std::size_t mOptionIndex;
        
    public:
        MenuState(StateStack& stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);

        void updateOptionText();
};

#endif // MENUSTATE_HPP