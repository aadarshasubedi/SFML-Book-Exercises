
#include <SFML/Graphics.hpp>
#include <gtest/gtest.h>

#include "../Game.hpp"

TEST(GameTests, testEagleLoaded) { 
    sf::Texture mTexture;
    auto result = mTexture.loadFromFile("./gfx/textures/eagle.png");
    ASSERT_EQ(true, result);
}

TEST(GameTests, testPlayerMovements){    
    sf::Texture mTexture;
    mTexture.loadFromFile("./gfx/textures/eagle.png");
        
    sf::Sprite mPlayer;
    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(0.f, 0.f);
    
    //move up
    sf::Vector2f movement(0.f, 0.f);
    movement.y -= 100.f;
    
    mPlayer.move(movement);
    
    auto result = mPlayer.getPosition().y;
    
    ASSERT_EQ(-100.f, result);
}
