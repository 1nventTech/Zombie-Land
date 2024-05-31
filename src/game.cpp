#include "character.h"
#include "enemy.h"
#include "game.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/View.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include <iostream>
#include <iterator>
#include <cstdlib>

sf::Vector2f enemySpawnRange(500.f, 500.f);

// Constructor & Destructor
Game::Game() {
    // Load font
    if (!font.loadFromFile("../assets/Jacquard12-Regular.ttf"))
        exit(EXIT_FAILURE);
    
    this->initVariables();
    this->initWindow();
}

Game::~Game() {
    std::cout << "Game\t\tdestructor called...\t\t(deleting player & camera)" << std::endl;
    delete this->player;
    delete this->camera;
    delete this->enemy;
    // for (auto &enemy : enemies) {
    //     delete enemy;
    // }
    // enemies.clear();
    cleanUp();  // enemys
}

// Private Functions
void Game::initWindow() {
    this->window = new sf::RenderWindow(this->vm, "Zombie land", sf::Style::Close);
    this->res.update(this->window);   // Update info about current window size
    this->player->reInit(this->window); // Fixed re-initializing

    this->camera->updateCameraSize(window->getSize().x, window->getSize().y);
    this->window->setView(this->camera->getCamera());
}

void Game::initVariables() {
    incrementW = 0;
    incrementS = 0;
    incrementA = 0;
    incrementD = 0;

    this->isFullScreen = false;
    this->show_pos = false;
    this->window = nullptr;

    this->vm.width = 1111;
    this->vm.height = 673;
    backgroundTexture.loadFromFile("../assets/grass.png");
    terrain = TerrainGenerator(backgroundTexture, sf::Vector2(res.width, res.height));

    this->player = new Player();
    this->camera = new Camera();
    this->enemy = new Enemy(); // Initialize the enemy
    this->enemy->set_target(*this -> player);
    enemySpawnInterval = sf::seconds(3.f); // Change this as needed
}

void Game::setTerrain() {
    terrain.getSprite().setPosition(this->player->getPlayer().getPosition().x - res.width, this->player->getPlayer().getPosition().y - res.height);
}

// Public Functions
const bool Game::running() const {
    return this->window->isOpen();
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->event_)) {
        switch (event_.type) {
            case sf::Event::MouseButtonPressed:
                if (!enemy->get_alive() && !enemy) this->enemy->xp_taken = true; this->player->xp += 40;
                this->enemy->takeDamage(10);
                break;
            case sf::Event::KeyReleased:
                switch (event_.key.code) {
                    case sf::Keyboard::Key::W:
                        this->player->top = false;
                        setTerrain();
                        break;
                    case sf::Keyboard::Key::A:
                        this->player->left = false;
                        setTerrain();
                        break;
                    case sf::Keyboard::Key::S:
                        this->player->bottom = false;
                        setTerrain();
                        break;
                    case sf::Keyboard::Key::D:
                        this->player->right = false;
                        setTerrain();
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                switch (event_.key.code) {
                    case sf::Keyboard::Key::Escape:
                        this->window->close();
                        break;
                    case sf::Keyboard::Key::Q:
                        this->window->close();
                        break;
                    case sf::Keyboard::Key::F11:
                        if (!(this->isFullScreen)) {
                            this->window->create(this->vm, "Zombie land", sf::Style::Fullscreen);
                            this->camera->updateCameraSize(window->getSize().x, window->getSize().y);
                            this->window->setView(this->camera->getCamera());
                            this->isFullScreen = true;
                            this->res.update(this->window);
                            this->player = new Player(this->window);
                            setTerrain();
                        } else {
                            this->window->create(this->vm, "Zombie land", sf::Style::Close);
                            this->camera->updateCameraSize(window->getSize().x, window->getSize().y);
                            this->window->setView(this->camera->getCamera());
                            this->isFullScreen = false;
                            this->res.update(this->window);
                            this->player = new Player(this->window);
                            setTerrain();
                        }
                        break;
                    case sf::Keyboard::Key::P:
                        this->show_pos = !this->show_pos;
                        break;
                    default:
                        break;
                }
                switch (event_.key.code) {
                    case sf::Keyboard::Key::W:
                        this->player->top = true;
                        if (incrementW == 3) {
                            setTerrain();
                            incrementW = 0;
                        }
                        incrementW++;
                        break;
                    case sf::Keyboard::Key::A:
                        this->player->left = true;
                        if (incrementA == 3) {
                            setTerrain();
                            incrementA = 0;
                        }
                        incrementA++;
                        break;
                    case sf::Keyboard::Key::S:
                        this->player->bottom = true;
                        if (incrementS == 3) {
                            setTerrain();
                            incrementS = 0;
                        }
                        incrementS++;
                        break;
                    case sf::Keyboard::Key::D:
                        this->player->right = true;
                        if (incrementD == 3) {
                            setTerrain();
                            incrementD = 0;
                        }
                        incrementD++;
                        break;
                    case sf::Keyboard::Key::I:
                        this->res.info();
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}

void Game::spawnEnemyRandomly() {
    for (int i = 0; i < 2000000; i++) {

    }
    // // Generate random x and y coordinates within the specified range
    // std::cout << "Enemy spawned\n";
    // int xxx = this->player->x + 300 + 50;
    // int yyy = this->player->y + 300 + 50;
    // // // Create a new enemy at the generated position
    // std::cout << "pos";
    // Enemy* newEnemy = new Enemy();
    // newEnemy->setPosition(xxx, yyy);
    // std::cout << "pos setup";
    // // // Add the enemy to the vector
    // enemies.push_back(newEnemy);
    // std::cout << "pushed";
    // delete newEnemy;
}


void Game::updateEnemies() {
    if (enemySpawnTimer.getElapsedTime() > enemySpawnInterval) {
        spawnEnemyRandomly();
        enemySpawnTimer.restart();
        std::cout << "spawned";
    }
    for (auto& enemy : enemies) {
        enemy->set_target(*this->player);
        enemy->follow();
        if (enemy->getGlobalBounds().intersects(this->player->getGlobalBounds())) {
            enemy->damage();
        }
        enemy->resetAttackCooldown();
    }
    // }

    // Update existing enemies
    for (auto it = enemies.begin(); it != enemies.end();) {
        (*it)->set_target(*this->player);
        (*it)->follow();
        if ((*it)->getGlobalBounds().intersects(this->player->getGlobalBounds())) {
            (*it)->damage();
        }
        (*it)->resetAttackCooldown();

        // // Remove enemies that are no longer alive
        // if ((*it)->check_alive()) {
        //     delete *it;
        //     it = enemies.erase(it);
        // } else {
        //     ++it;
        // }
    }
}
// void Game::spawnEnemyRandomly() {
//     // // Generate random x and y coordinates within the specified range
//     float x = static_cast<float>(rand() % static_cast<int>(2 * enemySpawnRange.x)) + this->player->x - enemySpawnRange.x;
//     float y = static_cast<float>(rand() % static_cast<int>(2 * enemySpawnRange.y)) + this->player->y - enemySpawnRange.y;

//     // Create a new enemy at the generated position
//     Enemy* newEnemy = new Enemy();
//     newEnemy->setPosition(x, y);

//     // Add the enemy to the vector
//     enemies.push_back(newEnemy);
// }

void Game::cleanUp() {
    // Clean up enemies
    for (auto& enemy : enemies) {
        delete enemy;
    }
    enemies.clear();
}


void Game::update() {
    this->pollEvents();

    // Enemy targeting player
    this->enemy->set_target(*this->player);
    this->enemy->follow();

    // check colision
    if (this->enemy->getGlobalBounds().intersects(this->player->getGlobalBounds())) {
        this->enemy->damage();
    }
    this->enemy->resetAttackCooldown();
    this -> updateEnemies();
}



void Game::render() {
    sf::CircleShape circle(20);
    circle.setPosition(-200, 0);
    circle.setFillColor(sf::Color(119, 58, 168));

    this->window->clear();
    this->camera->getCamera().setCenter(player->getPlayer().getPosition());
    this->window->setView(this->camera->getCamera());

    this->terrain.draw(this->window);
    this->window->draw(circle);

    // this->window->draw(this->player->getPlayer());
    this->player->render(*this->window);

    // Draw enemy
    // this->window->draw(this->enemy->getSprite());
    if (this->enemy->get_alive()) this->enemy->render(*this->window);
    for (auto &enemy : enemies) {
        this->window->draw(enemy->getSprite());
    }

    // Draw player info (HP and XP)
    this->window->draw(player->player_info(this->font, this->window));
    
    this->window->draw(player->get_sword());

    if (this->show_pos) {
        this->window->draw(player->pos_info(this->font, this->window));
    }

    this->window->display();
}

void Game::listen() {
    this->player->followMouse();
    if (this->player->top) this->player->move(0, -player->getVelocity() * dt.asSeconds());
    if (this->player->bottom) this->player->move(0, player->getVelocity() * dt.asSeconds());
    if (this->player->left) this->player->move(-player->getVelocity() * dt.asSeconds(), 0);
    if (this->player->right) this->player->move(player->getVelocity() * dt.asSeconds(), 0);
}
