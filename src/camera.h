#include "SFML/Graphics/View.hpp"

class Camera{
    int width, height, x, y;
    sf::View view;

public:
    Camera(int x = 0, int y = 0, int width = 0, int height = 0);
    ~Camera();
    void updateCameraPosition(float x, float y);
    void updateCameraSize(float x, float y);
    inline sf::View &getCamera(){
        return view;
    }

};
