#include <memory>

#include <SFML/Graphics.hpp>
#include <gtest/gtest.h>

#include "../ResourceHolder.hpp"
#include "../Aircraft.hpp"

TEST(AircraftTests, testEagleLoaded) { 
    sf::Texture mTexture;
    auto result = mTexture.loadFromFile("./gfx/textures/Eagle.png");
    ASSERT_EQ(true, result);
}

TEST(AircraftTests, testEagleLoadedByTextureID) {
    TextureHolder textures;
    textures.load(Textures::Eagle, "./gfx/textures/Eagle.png");
    std::unique_ptr<Aircraft> leader(new Aircraft(Aircraft::Eagle, textures));
    ASSERT_NE(nullptr, leader);
    ASSERT_EQ(8, sizeof(leader))
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
