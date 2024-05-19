#include <SFML/Graphics.hpp>
#include <iostream>
#ifndef bomb_h
#define bomb_h
using namespace sf;
using namespace std;
class Bomb
{
public:
    Texture tex;
    Sprite sprite;
    float bomb_speed = 0.1;
    float x, y;
    float w,h;
    Bomb(std::string png_path);
    float timer;
    void move();
};
Bomb ::Bomb(std::string png_path="img/bomb.png")
{
    tex.loadFromFile(png_path);
    sprite.setTexture(tex);
  
    sprite.setPosition(-200,-200);
    w=h=0;
    timer=0;
}
  
void Bomb::move()
{
    int i=0;
    sprite.move(0, bomb_speed); // controls speed
}



#endif