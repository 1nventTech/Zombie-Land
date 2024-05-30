#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>

class TerrainGenerator {
public:
    TerrainGenerator(const sf::Texture &texture=sf::Texture(), const sf::Vector2u& windowSize=sf::Vector2u(100,100));
    ~TerrainGenerator();
    void draw(sf::RenderWindow *window);
    inline sf::Sprite &getSprite(){
        return sprite;
    }

private:
    sf::Texture txt;
    sf::Sprite sprite;
    sf::Vector2u textureSize;
    sf::Vector2u windowSize;
};
