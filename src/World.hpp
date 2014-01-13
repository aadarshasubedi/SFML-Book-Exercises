#ifndef WORLD_HPP
#define WORLD_HPP

#include <array>
#include <queue>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "SceneNode.hpp"
#include "SpriteNode.hpp"
#include "Aircraft.hpp"
#include "CommandQueue.hpp"
#include "Command.hpp"

// Forward declaration
namespace sf {
    class RenderWindow;
}

class World : private sf::NonCopyable {

    private:
        enum Layer {
            Background,
            Air,
            LayerCount
        };
            
    private:
        sf::RenderWindow& mWindow;
        sf::View mWorldView;
        TextureHolder mTextures;

        SceneNode mSceneGraph;
        std::array<SceneNode*, LayerCount> mSceneLayers;
        CommandQueue mCommandQueue;

        sf::FloatRect mWorldBounds;
        sf::Vector2f mSpawnPosition;
        float mScrollSpeed;
	Aircraft* mPlayerAircraft;
        
    public:
        explicit World(sf::RenderWindow& window);
        void update(sf::Time dt);
        void draw();
        
        CommandQueue& getCommandQueue();

    private:
        void loadTextures();
        void buildScene();
        void adaptPlayerPosition();
        void adaptPlayerVelocity();
};

#endif // WORLD_HPP
