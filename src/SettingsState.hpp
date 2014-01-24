#ifndef SETTINGSSTATE_HPP
#define SETTINGSSTATE_HPP

#include <array>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Player.hpp"
#include "Container.hpp"
#include "Button.hpp"
#include "Label.hpp"


class SettingsState : public State {
    private:
        sf::Sprite mBackgroundSprite;
        GUI::Container mGUIContainer;
        std::array<GUI::Button::Ptr, Player::ActionCount> mBindingButtons;
        std::array<GUI::Label::Ptr, Player::ActionCount> mBindingLabels;

    public:
        SettingsState(StateStack& stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);

    private:
        void updateLabels();
        void addButtonLabel(Player::Action action, float y, const std::string& text, Context context);
};

#endif // SETTINGSSTATE_HPP
