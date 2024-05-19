#include <SFML/Graphics.hpp>
#include <string.h>
#include "enemy.h"
#ifndef laser_h
#define laser_h
using namespace sf;
class Laser
{
public:
    Texture tex;
    Sprite laser_sprite;
    float laser_speed = -1;
    float x, y;
    float w, h;
    Laser(std::string png_path = "img/PNG/Lasers/laserBlue01.png", float a = 381, float b = 528);
    // Laser y axis movement
    void move(bool, bool);
};
Laser ::Laser(std::string png_path, float a, float b)
{
    tex.loadFromFile(png_path);
    laser_sprite.setTexture(tex);
    x = a;
    y = b;
    laser_sprite.setPosition(x, y);
    if(png_path=="img/sprites/fireaddon_clock.png")
    laser_sprite.setScale(0.5,0.5);
    else if(png_path=="img/sprites/fireaddon_anti.png")
    laser_sprite.setScale(0.5,0.5);
    else if(png_path=="img/sprites/fireaddon.png")
    laser_sprite.setScale(0.5,0.5);
    else
    laser_sprite.setScale(1, 1);
    w = 9;
    h = 54;
}
void Laser::move(bool diag_left, bool diag_right)
{
    int move_x = 0;
    if (diag_left == 1)
    {
        move_x = laser_speed;
    }
    if (diag_right == 1)
    {
        move_x = -laser_speed;
    }
    laser_sprite.move(move_x, laser_speed); // controls speed
    
}

#endif
