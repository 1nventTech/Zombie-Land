#pragma once

#include "window_resolution.h"
#include "main_ch.h"

class Game {
	private:
		main_ch *player = new main_ch();
		bool isFullScreen;
		sf::RenderWindow * window;
		sf::Event event_;
		sf::VideoMode vm;
		WR::window_resolution res;
	// priv functions
	void initWindow();
	void initVariables();
	
	public: 
		Game ();
		virtual ~Game ();
	
		void update();
		void render();	
		
		void pollEvents();

		void listen();

		const bool running() const;
};
