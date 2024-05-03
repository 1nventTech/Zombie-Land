#include "./hearders/POS.h"
#include <iostream>

Pos::Pos(float x, float y): x(x), y(y) {}

Pos::~Pos() {
    std::cout << "Pos\t\tdestructor called...\n";
}