#include <functional>
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Mocks.hpp"



//Our test fixture
class ButtonTests: public testing::Test {
    public:
       typedef std::unique_ptr<GUI::Button> ButtonPtr;
    
    protected:
        virtual void SetUp() {}

        virtual void TearDown() { }
};

TEST_F(ButtonTests, testSetCallback){ 
    std::function<void()> callback;
    callback = [this] () {
        return "Woohoo!";
    };
    
    ASSERT_NE(nullptr, &callback);       
}

TEST_F(ButtonTests, testSetText){
    sf::Text text;    
    text.setString("Woohoo!");
    
    auto result = text.getString();
    
    ASSERT_EQ("Woohoo!", result);
    
    
}
TEST_F(ButtonTests, testSetToggle){
    bool IsToggle = true;
}

TEST_F(ButtonTests, testIsSelectable){}
TEST_F(ButtonTests, testSelect){}
TEST_F(ButtonTests, testDeselect){}

TEST_F(ButtonTests, testActivate){}
TEST_F(ButtonTests, testDeactivate){}

TEST_F(ButtonTests, testHandleEvent){}