#ifndef SOUNDNODE_HPP
#define SOUNDNODE_HPP

#include "SceneNode.hpp"
#include "ResourceIdentifiers.hpp"

class SoundPlayer;

class SoundNode : public SceneNode {
    private:
        SoundPlayer& mSounds;
        
    public:
        explicit SoundNode(SoundPlayer& player);
        void playSound(SoundEffect::ID sound, sf::Vector2f position);

        virtual unsigned int getCategory() const;
};

#endif // SOUNDNODE_HPP
