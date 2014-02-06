#ifndef EMITTERNODE_HPP
#define EMITTERNODE_HPP

#include "SceneNode.hpp"
#include "Particle.hpp"

class ParticleNode;

class EmitterNode : public SceneNode {
    public:
        explicit EmitterNode(Particle::Type type);
        
    private:
        sf::Time mAccumulatedTime;
        Particle::Type mType;
        ParticleNode* mParticleSystem;

    private:
        virtual void updateCurrent(sf::Time dt, CommandQueue& commands);

        void emitParticles(sf::Time dt);
};

#endif // EMITTERNODE_HPP
