#include <iostream>
#include "terrain_generation.h"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Sprite.hpp"

TerrainGenerator::TerrainGenerator(const sf::Texture &texture, const sf::Vector2u &windowSize) : windowSize(windowSize) {
    this->sprite.setTexture(texture);
    this->textureSize = texture.getSize();
    sf::Sprite newSprite(sf::Texture(),sf::IntRect(0,0,1680,1050));
    this->sprite = newSprite;
}
TerrainGenerator::~TerrainGenerator(){
    std::cout << "TerrainGenerator\t\tdestructor called...\n";
}

void TerrainGenerator::draw(sf::RenderWindow *window) {
    //ill fix this some 'other' day mkay
    this->txt.loadFromFile("../assets/grass.png"); 
    this->txt.setRepeated(true);
    this->sprite.setScale(2,2);
    this->sprite.setTexture(txt);

    window->draw(sprite);
}
