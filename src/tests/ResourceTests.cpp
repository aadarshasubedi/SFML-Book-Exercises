
#include <SFML/Graphics.hpp>
#include <gtest/gtest.h>

#include "../ResourceHolder.hpp"

TEST(GameTests, testEagleLoaded) { 
    sf::Texture mTexture;
    auto result = mTexture.loadFromFile("./gfx/textures/eagle.png");
    ASSERT_EQ(true, result);
}
