#include <memory>

#include <gtest/gtest.h>

#include <SFML/Graphics/RenderWindow.hpp>

#include "../BloomEffect.hpp"
#include "../State.hpp"

TEST(BloomEffectTests, testBloomEffectCreated) { 
    std::unique_ptr<BloomEffect> effect(new BloomEffect());
    ASSERT_NE(nullptr, &effect);    
}

TEST(BloomEffectTests, testApply){    
    std::unique_ptr<sf::RenderTarget> output(new sf::RenderWindow(sf::VideoMode(1024, 768), "Bloom Effect Test", sf::Style::Close));        //target 
    std::unique_ptr<sf::RenderTexture> input(new sf::RenderTexture());         //scene texture
    input->create(output->getSize().x, output->getSize().y);
    
    std::unique_ptr<BloomEffect> effect(new BloomEffect());
    effect->apply(*input, *output);
    
    
    
    
}


