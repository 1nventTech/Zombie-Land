#pragma once

#include "src/enemy.h"
#include "window_resolution.h"
#include "player.h"

class Game {
	private:
		Player *player = new Player();
		bool isFullScreen;
		sf::RenderWindow * window;
		sf::Event event_;
		sf::VideoMode vm;
		WR::window_resolution res;
		std::vector<Enemy> enemies;
	// priv functions
	void initWindow();
	void initVariables();
	
	public: 
		sf::Time dt;
		Game ();
		virtual ~Game ();
	
		void update();
		void render();	
		
		void pollEvents();

		void listen();

		const bool running() const;
};
