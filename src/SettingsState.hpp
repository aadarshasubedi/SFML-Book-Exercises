#ifndef SETTINGSSTATE_HPP
#define SETTINGSSTATE_HPP

#include <array>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "KeyBinding.hpp"
#include "Container.hpp"
#include "Button.hpp"
#include "Label.hpp"

class SettingsState : public State {
    private:
        sf::Sprite mBackgroundSprite;
        GUI::Container mGUIContainer;
        std::array<GUI::Button::Ptr, 2*PlayerAction::Count> mBindingButtons;
        std::array<GUI::Label::Ptr, 2*PlayerAction::Count> mBindingLabels;
            
    public:
        SettingsState(StateStack& stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event& event);

    private:
        void updateLabels();
        void addButtonLabel(std::size_t index, std::size_t x, std::size_t y, const std::string& text, Context context);
};

#endif // SETTINGSSTATE_HPP
