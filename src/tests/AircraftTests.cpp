#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <gtest/gtest.h>


#include "Mocks.hpp"

#include "../ResourceHolder.hpp"
#include "../ResourceIdentifiers.hpp"

class AircraftTests: public testing::Test {
    public:
        typedef std::unique_ptr<Aircraft> AircraftPtr;
        TextureHolder mTextures;
        FontHolder mFonts;
        
    protected:
        virtual void SetUp() {
            mTextures.load(Textures::Entities, "./gfx/textures/Entities.png");
            mFonts.load(Fonts::Main, "./gfx/Sansation.ttf");
        }

        virtual void TearDown() { }
};

TEST_F(AircraftTests, testAircraftCreated) { 
   // AircraftPtr eagle(new Aircraft(Aircraft::Eagle, mTextures, mFonts));  //CAN'T FIND EXPLOSION TEXTURE?
    //eagle->setIdentifier(1);
    //ASSERT_NE(nullptr, &eagle);
}

TEST_F(AircraftTests, testgetCategory) {}
TEST_F(AircraftTests, testgetBoundingRect) {}
TEST_F(AircraftTests, testremove) {}
TEST_F(AircraftTests, testisMarkedForRemoval) {};
TEST_F(AircraftTests, testisAllied) {}
TEST_F(AircraftTests, testgetMaxSpeed) {}
TEST_F(AircraftTests, testdisablePickups) {}

TEST_F(AircraftTests, testincreaseFireRate) {}
TEST_F(AircraftTests, testincreaseSpread) {}
TEST_F(AircraftTests, testcollectMissiles) {}

TEST_F(AircraftTests, testfire) {}
TEST_F(AircraftTests, testlaunchMissile) {}
TEST_F(AircraftTests, testplayLocalSound) {}
TEST_F(AircraftTests, testgetIdentifier) {}
TEST_F(AircraftTests, testsetIdentifier) {}
TEST_F(AircraftTests, testgetMissileAmmo) {}
TEST_F(AircraftTests, testsetMissileAmmo) {}
 
