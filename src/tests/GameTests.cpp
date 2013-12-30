
#include <SFML/Graphics.hpp>
#include <gtest/gtest.h>

#include "../Game.hpp"

TEST(GameTests, testEagleLoaded) { 
    sf::Texture mTexture;
    bool result = mTexture.loadFromFile("../gfx/textures/eagle.png");
    ASSERT_EQ(true, result);
}
  
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}