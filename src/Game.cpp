#include "Game.h"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include <iostream>

// Contructor & Destructor

Game::Game() {
    // this -> Tit = gamename;
    this -> initVariables();
    this -> initWindow();
}

Game::~Game() {
    this->res.~window_resolution();
    std::cout << "Game\t\tdestructor called...\t\t(deleting player & window)" << std::endl;
    delete this -> player;
    delete this -> window; 
}

// Private Functions

void Game::initWindow() {
    this -> window = new sf::RenderWindow(this -> vm, "Zombie land", sf::Style::Close);
    // this -> player.setPosition(this -> window ->getSize().x / 2, this -> window ->getSize().y / 2);
    this ->res.update(this ->window);   // update info about current window size
    // this -> player = new main_ch(this->window);     // re_init function made some mess but
    this -> player -> re_init(this-> window);           // fixed re_initializing
}

void Game::initVariables() {
    this -> isFullScreen = false;
    this -> window = nullptr;

    this -> vm.width = 1111;
    this -> vm.height = 673;
}

// Public Functions

const bool Game::running() const {
    return this -> window -> isOpen();
}

void Game::pollEvents() {
        while (this -> window -> pollEvent(this -> event_)) {
            switch(event_.type) {
                case sf::Event::KeyReleased:
                    switch (event_.key.code) {
                        case sf::Keyboard::Key::W:
                            this->player->top = (bool)0;
                            break;
                        case sf::Keyboard::Key::A:
                            this->player->left = (bool)0;
                            break;
                        case sf::Keyboard::Key::S:
                            this->player->bottom = (bool)0;
                            break;
                        case sf::Keyboard::Key::D:
                            this->player->right = (bool)0;
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
                                this -> isFullScreen = true;
                                this -> res.update(this -> window); 
                                this -> player = new main_ch(this->window);
                            } else {
                                this -> window -> create(this -> vm, "Zombie land", sf::Style::Close);
                                this -> isFullScreen = false;
                                this -> res.update(this -> window); 
                                this -> player = new main_ch(this->window);     // again this fucking reinit won't work idk why
                            }
                            break;
                        }
                        // player interactions with kkeyboard
                        case sf::Keyboard::Key::W:
                            this->player->top = true;
                            break;
                        case sf::Keyboard::Key::A:
                            this->player->left = true;
                            break;
                        case sf::Keyboard::Key::S:
                            this->player->bottom = true;
                            break;
                        case sf::Keyboard::Key::D:
                            this->player->right = true;
                            break;
                        case sf::Keyboard::Key::I:
                            this -> res.info();
                            break;
                    }   // end ^ switch(event_.key.code)
                    break;
            }
        }
}

void Game::update() {
    this -> pollEvents();
}

void Game::render() {
    this -> window -> clear();   
    this -> window -> draw(this->player->get_main_ch());
    this -> window -> display();
}

void Game::listen() {
    this -> player -> follow_mouse();
    if (this->player->top) this->player->move(0, -0.5);
    if (this->player->bottom) this->player->move(0, 0.5);
    if (this->player->left) this->player->move(-0.5, 0);
    if (this->player->right) this->player->move(0.5, 0);
}