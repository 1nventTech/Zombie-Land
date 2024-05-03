#pragma once

#include "WINDOW_RESOLUTION.h"
#include "CHARACTERS.h"
#include "POS.h"

class LOOP {
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
		LOOP ();
		virtual ~LOOP ();
	
		void update();
		void render();	
		
		void pollEvents();

		void listen();

		const bool running() const;
};
