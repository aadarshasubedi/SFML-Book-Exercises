#ifndef KEYBINDING_HPP
#define KEYBINDING_HPP

#include <map>
#include <vector>

#include <SFML/Window/Keyboard.hpp>

namespace PlayerAction {
    enum Type {
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown,
        Fire,
        LaunchMissile,
        Count
    };
}

bool isRealtimeAction(PlayerAction::Type action);

class KeyBinding {
    public:
        typedef PlayerAction::Type Action;

    private:
        std::map<sf::Keyboard::Key, Action> mKeyMap;

    public:
        explicit KeyBinding(int controlPreconfiguration);

        void assignKey(Action action, sf::Keyboard::Key key);
        sf::Keyboard::Key getAssignedKey(Action action) const;

        bool checkAction(sf::Keyboard::Key key, Action& out) const;
        std::vector<Action> getRealtimeActions() const;

    private:
        void initializeActions();
};

#endif // KEYBINDING_HPP
