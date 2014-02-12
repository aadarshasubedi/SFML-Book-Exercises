#ifndef MOCKS_HPP
#define	MOCKS_HPP

#include <gmock/gmock.h>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

#include "../Aircraft.hpp"

class MockAircraft : public Aircraft {
    public:
        MOCK_CONST_METHOD0(getCategory, unsigned int());
        //virtual unsigned int getCategory() const;
        MOCK_CONST_METHOD0(getBoundingRect, sf::FloatRect());
        //virtual sf::FloatRect getBoundingRect() const;
        MOCK_METHOD0(remove, void());
        //virtual void remove();
        MOCK_CONST_METHOD0(isMarkedForRemoval, bool());
        //virtual bool isMarkedForRemoval() const;
        MOCK_CONST_METHOD2(drawCurrent, void(sf::RenderTarget& target, sf::RenderStates states));
        //virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
        MOCK_METHOD2(updateCurrent, void(sf::Time dt, CommandQueue& commands));
        //virtual void updateCurrent(sf::Time dt, CommandQueue& commands);
};

#include "../Animation.hpp"

class MockAnimation : public Animation {
        
};

#include "../Application.hpp"

class MockApplication : public Application {
        
};

#include "../BloomEffect.hpp"

class MockBloomEffect : public BloomEffect {
    public:
        MOCK_METHOD2(apply, void(const sf::RenderTexture& input, sf::RenderTarget& output));
        //virtual void apply(const sf::RenderTexture& input, sf::RenderTarget& output);
    
};

#include "../Button.hpp"

//our mock object with our virtual public implementations
class MockButton : public GUI::Button {
    public:
        MOCK_CONST_METHOD0(isSelectable, bool());
        MOCK_METHOD0(select, void());
        MOCK_METHOD0(deselect, void());

        MOCK_METHOD0(activate, void());
        MOCK_METHOD0(deactivate, void());
        MOCK_METHOD1(handleEvent, void(const sf::Event& event));
};

// Templates to help with mocking our non-virtual implementations. 
// For example, in our tests:  
template <class GUI::Button>
void setCallback(GUI::Button* btn, std::function<void()> callback){
    
}

template <class GUI::Button>
void setText(GUI::Button* btn, const std::string& text){

}

template <class GUI::Button>
void setToggle(GUI::Button* btn, bool flag){

}


#endif	/* MOCKS_HPP */

