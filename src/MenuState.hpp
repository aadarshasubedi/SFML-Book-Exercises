#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Container.hpp"

class MenuState : public State {
    private:
        sf::Sprite mBackgroundSprite;
        GUI::Container mGUIContainer;

    public:
        MenuState(StateStack& stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);
};

#endif // MENUSTATE_HPP
