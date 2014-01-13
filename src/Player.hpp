#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <map>

#include <SFML/Window/Event.hpp>

#include "Command.hpp"

class CommandQueue;

class Player {
    public:
        enum Action {
            MoveLeft,
            MoveRight,
            MoveUp,
            MoveDown,
            ActionCount
        };

    private:
        std::map<sf::Keyboard::Key, Action> mKeyBinding;
        std::map<Action, Command> mActionBinding;

    public:
        Player();
        void handleEvent(const sf::Event& event, CommandQueue& commands);
        void handleRealtimeInput(CommandQueue& commands);

        void assignKey(Action action, sf::Keyboard::Key key);
        sf::Keyboard::Key getAssignedKey(Action action) const;

    private:
        void initializeActions();
        static bool isRealtimeAction(Action action);
};

#endif // PLAYER_HPP