#ifndef GAME_HPP
#define	GAME_HPP

#include <SFML/Graphics.hpp>

class Game {
    public:
        Game();
        void run();

    private:
        void processEvents();
        void update(sf::Time elapsedTime);
        void render();
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
        
    private:
        static const float PlayerSpeed;
        static const sf::Time TimePerFrame;
        
        sf::RenderWindow mWindow;
        sf::Sprite mPlayer; 
        sf::Texture mTexture;
        
        bool mIsMovingUp;
        bool mIsMovingLeft;
        bool mIsMovingRight;
        bool mIsMovingDown;
};

#endif	/* GAME_HPP */

