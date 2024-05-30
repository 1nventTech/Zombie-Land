#include "axis.h"

Axis::Axis(float x, float y): x(x), y(y) {}

void Axis::update(float x, float y) {
    this -> x = x;
    this -> y = y;
}

Axis::~Axis() {}