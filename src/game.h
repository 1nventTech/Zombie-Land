#pragma once

#include "SFML/Graphics/View.hpp"
#include "enemy.h"
#include "window_resolution.h"
#include "player.h"
#include "camera.h"
#include "terrain_generation.h"

class Game {
	private:
		Player *player = new Player();
		Camera *camera = new Camera();

		sf::Texture backgroundTexture;
		bool isFullScreen;
		bool show_pos;
		sf::RenderWindow *window;
		TerrainGenerator terrain;
		sf::Event event_;
		sf::VideoMode vm;
		sf::View terrainView;
		WR::window_resolution res;
		std::vector<Enemy> enemies;
		int incrementW;
		int incrementS;
		int incrementA;
		int incrementD;

		// font
		sf::Font font;
		

	// priv functions
		void initWindow();
		void initVariables();
		void setTerrain();
	
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
