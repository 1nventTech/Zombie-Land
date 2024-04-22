#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Game {
	private:
	bool isFullScreen;
		sf::RenderWindow * window;
		sf::Event event_;
		sf::VideoMode vm;
	// priv functions
	void initWindow();
	void initVariables();
	
	public: 
		Game ();
		virtual ~Game ();
	
		void update();
		void render();	
		
		void pollEvents();

		const bool running() const;
};
