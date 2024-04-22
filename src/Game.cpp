#include "Game.h"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/WindowEnums.hpp"
#include <iostream>

// Contructor & Destructor

Game::Game() {
    // this -> Tit = gamename;
    this -> initVariables();
    this -> initWindow();
}

Game::~Game() {
    std::cout << "destoying window..." << std::endl;
    delete this -> window; 
}

// Private Functions

void Game::initWindow() {
    this -> window = new sf::RenderWindow(this -> vm, "Zombie land", sf::Style::Close);
}

void Game::initVariables() {
    this -> isFullScreen = false;
    this -> window = nullptr;

    this -> vm.size.x = 800;
    this -> vm.size.y = 600;
}

// Public Functions

const bool Game::running() const {
    return this -> window -> isOpen();
}

void Game::pollEvents() {
        while (this -> window -> pollEvent(this -> event_)) {
            switch(event_.type) {
                case sf::Event::Closed: 
                    this -> window -> close();
                    break;
                case sf::Event::KeyPressed:
                    switch(event_.key.code){
                        case sf::Keyboard::Key::Escape:
                        case sf::Keyboard::Key::Q:
                            this -> window -> close();
                            break;
                        case sf::Keyboard::Key::F11: {
                            if (!(this -> isFullScreen)) {
                                this -> window -> create(this -> vm, "Zombie land", sf::Style::Default);
                                this -> isFullScreen = true;
                            } else {
                                this -> window -> create(this -> vm, "Zombie land", sf::Style::Close);
                                this -> isFullScreen = false;
                            }
                        }
                        break;
                    }
                    break;
            }
        }
}

void Game::update() {
    this -> pollEvents();
}

void Game::render() {
    this -> window -> clear(sf::Color(0, 255, 100, 255));   

    this -> window -> display();
}
