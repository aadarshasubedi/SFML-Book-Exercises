#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "World.hpp"
#include "Player.hpp"

class Game : private sf::NonCopyable {
        
    private:
        static const sf::Time TimePerFrame;

        sf::RenderWindow mWindow;
        World mWorld;
        Player mPlayer;

        sf::Font mFont;
        sf::Text mStatisticsText;
        sf::Time mStatisticsUpdateTime;
        std::size_t mStatisticsNumFrames;
        
    public:
        Game();
        void run();

    private:
        void processInput();
        void update(sf::Time elapsedTime);
        void render();

        void updateStatistics(sf::Time elapsedTime);
};

#endif // GAME_HPP
