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

        struct SpawnPoint {
            SpawnPoint(Aircraft::Type type, float x, float y)
            : type(type)
            , x(x)
            , y(y) { }

            Aircraft::Type type;
            float x;
            float y;
        };
            
    private:
        sf::RenderWindow& mWindow;
        sf::View mWorldView;
        TextureHolder mTextures;
        FontHolder& mFonts;

        SceneNode mSceneGraph;
        std::array<SceneNode*, LayerCount> mSceneLayers;
        CommandQueue mCommandQueue;

        sf::FloatRect mWorldBounds;
        sf::Vector2f mSpawnPosition;
        float mScrollSpeed;
        Aircraft* mPlayerAircraft;

        std::vector<SpawnPoint> mEnemySpawnPoints;
        std::vector<Aircraft*> mActiveEnemies;
        
    public:
        explicit World(sf::RenderWindow& window, FontHolder& fonts);
        void update(sf::Time dt);
        void draw();

        CommandQueue& getCommandQueue();

        bool hasAlivePlayer() const;
        bool hasPlayerReachedEnd() const;

    private:
        void loadTextures();
        void adaptPlayerPosition();
        void adaptPlayerVelocity();
        void handleCollisions();

        void buildScene();
        void addEnemies();
        void addEnemy(Aircraft::Type type, float relX, float relY);
        void spawnEnemies();
        void destroyEntitiesOutsideView();
        void guideMissiles();
        sf::FloatRect getViewBounds() const;
        sf::FloatRect getBattlefieldBounds() const;
};

#endif // WORLD_HPP
