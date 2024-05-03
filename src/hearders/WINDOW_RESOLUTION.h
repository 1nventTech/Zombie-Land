#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


namespace WR {
    class window_resolution {
        public:
            unsigned int width;
            unsigned int height;
            // constructor | destructor
            window_resolution(const unsigned int x = 0, const unsigned int y = 0): width(x), height(y) {}
            virtual ~window_resolution();
            // functions
            void update(sf::RenderWindow *w);
            void info();

    };
} // namespace WR