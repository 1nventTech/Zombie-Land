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
		// Enemy  *enemy = new Enemy();
		sf::Texture backgroundTexture;
		bool isFullScreen;
		bool show_pos;
		sf::RenderWindow *window;
		TerrainGenerator terrain;
		sf::Event event_;
		sf::VideoMode vm;
		sf::View terrainView;
		WR::window_resolution res;
		int incrementW;
		int incrementS;
		int incrementA;
		int incrementD;

		// font
		sf::Font font;
		
		// Enemy spawning
		sf::Clock enemySpawnTimer;
		sf::Time enemySpawnInterval;
		sf::Vector2f enemySpawnRange;

		std::vector<Enemy*> enemies; // Store pointers to enemies

		// Private functions
		void spawnEnemyRandomly();
		void updateEnemies();
		void renderEnemies();
	// priv functions
		void initWindow();
		void initVariables();
		void setTerrain();
		void cleanUp();
	
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
