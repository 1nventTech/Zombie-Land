#include "camera.h"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/View.hpp"
Camera::Camera(int width, int height, int x, int y){
    this->view.reset(sf::FloatRect(x,y,width,height));
}
Camera::~Camera(){}
    
void Camera::updateCameraPosition(float x, float y){
    this->view.move(x,y);
}
void Camera::updateCameraSize(float w, float h){
    this->view.setSize(w,h);
}
