#include "game.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/View.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include <iostream>
#include <iterator>
#include <cstdlib>

// Contructor & Destructor
#define SetTerrainX() 

Game::Game() {
    // load font
    if (!font.loadFromFile("../assets/Jacquard12-Regular.ttf"))
        exit(EXIT_FAILURE);
    //
    this -> initVariables();
    this -> initWindow();
}

Game::~Game() {
    this->res.~window_resolution();
    std::cout << "Game\t\tdestructor called...\t\t(deleting player & camera)" << std::endl;
    delete this -> player;
    delete this -> camera;
}

// Private Functions

void Game::initWindow() {
    this -> window = new sf::RenderWindow(this -> vm, "Zombie land", sf::Style::Close);
    // this -> player.setPosition(this -> window ->getSize().x / 2, this -> window ->getSize().y / 2);
    this ->res.update(this -> window);   // update info about current window size
    // this -> player = new Player(this->window);     // re_init function made some mess but
    this -> player -> reInit(this -> window);           // fixed re_initializing

    this -> camera -> updateCameraSize(window->getSize().x,window->getSize().y);
    this -> window -> setView(this->camera->getCamera()); 

}
void Game::initVariables() {
    incrementW = 0;
    incrementS = 0;
    incrementA = 0;
    incrementD = 0;

    this -> isFullScreen = false;
    this -> window = nullptr;

    this -> vm.width = 1111;
    this -> vm.height = 673;
    backgroundTexture.loadFromFile("../assets/grass.png");
    TerrainGenerator terrain(backgroundTexture,sf::Vector2(res.width,res.height));


}
void Game::setTerrain(){
    terrain.getSprite().setPosition(this->player->getPlayer().getPosition().x-res.width, this->player->getPlayer().getPosition().y-res.height);     
}

// Public Functions

const bool Game::running() const {
    return this -> window -> isOpen();
}
void Game::pollEvents() {
        while (this -> window -> pollEvent(this -> event_)) {
            // player->player_info(this -> font, this->window);  // display player stats 
            switch(event_.type) {
                case sf::Event::KeyReleased:
                    switch (event_.key.code) {
                        case sf::Keyboard::Key::W:
                            this->player->top = (bool)0;
                            setTerrain();
                            break;
                        case sf::Keyboard::Key::A:
                            this->player->left = (bool)0;
                            if(this->player->top){
                                

                            }
                            setTerrain();
                            break;
                        case sf::Keyboard::Key::S:
                            this->player->bottom = (bool)0;
                            setTerrain();
                            break;
                        case sf::Keyboard::Key::D:
                            this->player->right = (bool)0;
                            setTerrain();
                            break;  
                        default:
                            break;
                    }
                    break;
                case sf::Event::Closed: 
                    this -> window -> close();
                    break;
                case sf::Event::KeyPressed:
                    switch(event_.key.code) {
                        case sf::Keyboard::Key::Escape:
                            this -> window -> close();
                            break;
                        case sf::Keyboard::Key::Q:
                            this -> window -> close();
                            break;
                        case sf::Keyboard::Key::F11: {
                            if (!(this -> isFullScreen)) {
                                this -> window -> create(this -> vm, "Zombie land", sf::Style::Fullscreen);
                                this -> camera -> updateCameraSize(window->getSize().x,window->getSize().y);
                                this -> window->setView(this->camera->getCamera());
                                this -> isFullScreen = true;
                                this -> res.update(this -> window); 
                                this -> player = new Player(this->window);
                                setTerrain();
                            } else {
                                this -> window -> create(this -> vm, "Zombie land", sf::Style::Close);
                                this -> camera -> updateCameraSize(window->getSize().x,window->getSize().y);
                                this -> window->setView(this->camera->getCamera());
                                this -> isFullScreen = false;
                                this -> res.update(this -> window); 
                                this -> player = new Player(this->window);     // again this fucking reinit won't work idk why
                                setTerrain();
                            }
                            break;
                        default:
                            break;
                        }
                        // player interactions with keyboard
                        case sf::Keyboard::Key::W:
                            this->player->top = true;
                            //this way is better but.....idk
                            //if(((int)(this->player->getPlayer().getPosition().y) % 33) == 0){
                            //    terrain.getSprite().setPosition(this->player->getPlayer().getPosition().x-(res.width * 2 / 2),this->player->getPlayer().getPosition().y-(res.height * 2 / 2));     
                            //}
                            if(incrementW == 3){
                                setTerrain();
                                incrementW = 0;
                            }
                            incrementW++;
                            break;
                        case sf::Keyboard::Key::A:
                            this->player->left = true;
                            if(incrementA == 3){
                                setTerrain();
                                incrementA = 0;
                            }
                            incrementA++;
                            break;
                        case sf::Keyboard::Key::S:
                            this->player->bottom = true;
                            if(incrementS == 3){
                                setTerrain();
                                incrementS = 0;
                            }
                            incrementS++;
                            break;
                        case sf::Keyboard::Key::D:
                            this->player->right = true;
                            if(incrementD == 3){
                                setTerrain();
                                incrementD = 0;
                            }
                            incrementD++;
                            break;
                        case sf::Keyboard::Key::I:
                            this -> res.info();
                            break;
                    }   // end ^ switch(event_.key.code)
                    break;
                        default:
                            break;
            }
        }
}
void Game::update() {
    this -> pollEvents();
}

void Game::render() {
    sf::CircleShape circle(20);
    circle.setPosition(-200, 0);
    circle.setFillColor(sf::Color(119, 58, 168));

    this->window->clear();
    this->camera->getCamera().setCenter(player->getPlayer().getPosition());
    this->window->setView(this->camera->getCamera());

    this->terrain.draw(this->window);
    this->window->draw(this->player->getPlayer());
    this->window->draw(circle);

    // Draw player info (HP and XP)
    this->window->draw(player->player_info(this->font, this->window));

    this->window->display();
}


void Game::listen() {
    this -> player -> followMouse();
    if (this->player->top) this->player->move(0, -player->velocity * dt.asSeconds());   
    if (this->player->bottom) this->player->move(0, player->velocity * dt.asSeconds()); 
    if (this->player->left) this->player->move(-player->velocity * dt.asSeconds(), 0);  
    if (this->player->right) this->player->move(player->velocity * dt.asSeconds(), 0);  
}
