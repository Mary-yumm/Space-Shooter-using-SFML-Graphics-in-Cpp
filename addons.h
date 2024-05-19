#include "player.h"
#include "laser.h"
#ifndef addons_h
#define addons_h
class Addons
{
public:
    Texture tex;
    Sprite sprite;
    int x, y;
    float w, h;
    float speed;
    int current_size;
    string type;
    bool active;
    Addons();
    virtual void draw(sf::RenderWindow &window) = 0;
};
Addons::Addons()
{
    active = 0;
    current_size = 0;
    speed = 0.2;
}


//-----------------------------------Power Up---------------------------
class PowerUp : public Addons
{
public:
    PowerUp();
    virtual void draw(sf::RenderWindow &window) override;
};
PowerUp::PowerUp()
{
    if (!tex.loadFromFile("img/sprites/powerup4.png"))
    {
        std::cout << "Error loading texture" << std::endl;
    }
    sprite.setTexture(tex);
    int random = rand() % 730 + 1;
    sprite.setPosition(random, 0);
    sprite.setScale(0.2, 0.2);
    type = "Power Up";
    w=45;h=45;
}
void PowerUp::draw(sf::RenderWindow &window)
{
    window.draw(sprite); 
}

//----------------------------------Fire----------------------------
class Fire : public Addons
{
public:
    Fire();
    void draw(sf::RenderWindow &window);
};
Fire::Fire()
{
    tex.loadFromFile("img/sprites/fire4.png");
    sprite.setTexture(tex);
    int random = rand() % 730 + 1;
    sprite.setPosition(random, 0);
    sprite.setScale(0.2, 0.2);
    type = "Fire";
    w=45;h=45;
}
void Fire::draw(sf::RenderWindow &window)
{
    window.draw(sprite); 
}

//--------------------------------Lives------------------------------
class Lives : public Addons
{
public:
    Lives();
    void draw(sf::RenderWindow &window);
};
Lives::Lives()
{
    tex.loadFromFile("img/sprites/life2.png");
    sprite.setTexture(tex);
    sprite.setScale(0.2, 0.2);
    int random = rand() % 730 + 1;
    sprite.setPosition(random, 0);
    type = "Lives";
    w=45;h=45;
}
void Lives::draw(sf::RenderWindow &window)
{
    window.draw(sprite); 
}

//-------------------------------Danger-----------------------------
class Danger : public Addons
{
public:
    Danger();
    void draw(sf::RenderWindow &window);
};
Danger::Danger()
{
    tex.loadFromFile("img/sprites/danger3.png");
    sprite.setTexture(tex);
    sprite.setScale(0.2, 0.2);
    int random = rand() % 730 + 1;
    sprite.setPosition(random, 0);
    type = "Danger";
    w = 43.8;
    h = 37.6;
  
}
void Danger::draw(sf::RenderWindow &window)
{
    window.draw(sprite); 
}

#endif