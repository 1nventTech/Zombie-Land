#pragma once

#include <SFML/Graphics.hpp>

class Pos {
    public:
        float x;
        float y;
        Pos(float x = 0, float y = 0);
        virtual ~Pos();
};

class main_ch final : public Pos {
    private:
        sf::RectangleShape *body;
        sf::RenderWindow *win;
    public:
        bool left, right, top, bottom;
        main_ch(sf::RenderWindow *w = nullptr);
        ~main_ch();
        void upgrade_ch();
        sf::RectangleShape get_main_ch();
        void re_init(sf::RenderWindow *w);
        void follow_mouse();
        void move(float x, float y);
};