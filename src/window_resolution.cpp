#include "window_resolution.h"
#include <iostream>

WR::window_resolution::~window_resolution() {
   std::cout << "Win_Res\t\tdestructor called...\n"; 
}

void WR::window_resolution::update(sf::RenderWindow *w) {
    this -> width = w ->  getSize().x;
    this -> height = w -> getSize().y;
}

void WR::window_resolution::info() {
    using std::cout;
    cout << "width: " << this -> width << "\nheight: " << this -> height << '\n';
    return;
}