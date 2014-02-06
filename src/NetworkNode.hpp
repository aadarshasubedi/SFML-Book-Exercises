#ifndef NETWORKNODE_HPP
#define NETWORKNODE_HPP

#include <queue>

#include "SceneNode.hpp"
#include "NetworkProtocol.hpp"

class NetworkNode : public SceneNode {
    private:
        std::queue<GameActions::Action>	mPendingActions;

    public:
        NetworkNode();

        void notifyGameAction(GameActions::Type type, sf::Vector2f position);
        bool pollGameAction(GameActions::Action& out);

        virtual unsigned int getCategory() const;
};

#endif // NETWORKNODE_HPP
