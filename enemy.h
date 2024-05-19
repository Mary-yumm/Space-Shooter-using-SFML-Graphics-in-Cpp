#include "bomb.h"
#ifndef enemy_h
#define enemy_h
#include "laser.h"

class Enemy
{
public:
    Texture tex;
    Sprite sprite;
    Bomb *bomb;
    Clock clock;
    float timer;
    int x, y;
    float w, h;
    int speed;
    float interval;
    int total;
    int score_inc;
    bool flag;
    Enemy(Bomb *b);
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual ~Enemy() = default;
    virtual bool move() = 0;
};
Enemy::Enemy(Bomb *b = NULL)
{
    total = 1;
    w = h = 0;
    score_inc = 0;
    timer = 0;
    flag = 0;
}
class Monster : public Enemy
{
public:
    Monster(Bomb *b);
    virtual bool move() override;
    virtual void draw(sf::RenderWindow &window) override;
};

Monster::Monster(Bomb *b)
{
    if (!tex.loadFromFile("img/monster1.png"))
    {
        std::cout << "Error loading texture" << std::endl;
    }
    sprite.setTexture(tex);
    x = 340;
    y = 50;
    sprite.setPosition(x, y);
    sprite.setScale(0.3, 0.3);
    bomb->sprite.setPosition(x + 90, y + 100);
    bomb->sprite.setScale(1, 5);
    bomb = b;
    bomb->w = 52;
    bomb->h = 496;
    score_inc = 40;
}
bool Monster::move()
{
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    bomb->timer += time;
    float sp = 0.3;
    if (sprite.getPosition().x > 600) // right side
    {
        flag = 1;
    }
    if (sprite.getPosition().x < 1) // left
    {
        flag = 0;
    }
    if (sprite.getPosition().x < 600 && flag == 0)
    {
        sprite.move(sp, 0);
    }
    else if (sprite.getPosition().x > 0 && flag == 1)
    {
        sprite.move(-sp, 0);
    }

    if (timer > 2.5 && bomb->sprite.getPosition().y == 180)
    {
        bomb->sprite.setPosition(-200, -200);
        bomb->timer = 0;
    }
    else if (bomb->sprite.getPosition().y == 180 && bomb->timer > 2)
    {
        if (sprite.getPosition().x < 600 && flag == 0)
        {
            bomb->sprite.move(sp, 0);
        }
        else if (sprite.getPosition().x > 0 && flag == 1)
        {
            bomb->sprite.move(-sp, 0);
        }
    }
    else if (bomb->timer > 2)
    {

        bomb->sprite.setPosition(sprite.getPosition().x + 80, 180);
        bomb->sprite.setScale(1, 3.2);
    }
    return 0;
}
void Monster::draw(sf::RenderWindow &window)
{
    window.draw(bomb->sprite);
    window.draw(sprite);
}

//---------------------------------Dragon-------------------------
class Dragon : public Enemy
{
public:
    Dragon(Bomb *b);
    virtual bool move() override;
    virtual void draw(sf::RenderWindow &window) override;
};

Dragon::Dragon(Bomb *b)
{
    if (!tex.loadFromFile("img/dragon.png"))
    {
        std::cout << "Error loading texture" << std::endl;
    }
    sprite.setTexture(tex);
    x = 200;
    y = 0;
    sprite.setPosition(x, y);
    sprite.setScale(1.5, 1.5);
    bomb->sprite.setScale(0.5, 0.5);
    bomb = b;
    bomb->w = 104;
    bomb->h = 104.5;
    score_inc = 40;
    bomb->sprite.setPosition(x + 130, y + 300);
}
bool Dragon::move()
{
    return 0;
}
void Dragon::draw(sf::RenderWindow &window)
{
    window.draw(bomb->sprite);
    window.draw(sprite);
}
//------------------------------Invaders----------------------------
class Invaders : public Enemy
{
public:
    Invaders(Bomb *b = NULL);
    virtual void draw(sf::RenderWindow &window) override;
    virtual bool move() = 0;
    bool flag;
};
Invaders::Invaders(Bomb *b)
{
    speed = 1;
    interval = 0;
    timer = 0;
    w = h = 0;
}
void Invaders::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}
//---------------------------------Alpha----------------------------
class Alpha : public Invaders
{
public:
    Alpha(Bomb *b);
    virtual void draw(sf::RenderWindow &window) override;
    bool move();
};

Alpha::Alpha(Bomb *b)
{
    if (!tex.loadFromFile("img/enemy_1.png"))
    {
        std::cout << "Error loading texture" << std::endl;
    }
    sprite.setTexture(tex);
    sprite.setScale(0.4, 0.5);
    interval = 5;
    bomb = b;
    bomb->sprite.setScale(0.25, 0.25);
    timer = 0;
    flag = 0;
    w = 48;
    h = 61.6;
    score_inc = 10;
    bomb->h = 45;
    bomb->w = 45;
}
bool Alpha::move()
{
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;
    if (timer >= interval)
    {
        if (flag == 0)
        {
            bomb->sprite.setPosition(sprite.getPosition().x + 10, sprite.getPosition().y);
            flag = 1;
        }
        bomb->move();
    }
    if (bomb->sprite.getPosition().y > 600)
    {
        timer = -interval;
        flag = 0;
        bomb->sprite.setPosition(-100, -100);
        return 1;
    }
    return 0;
}
void Alpha::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
    window.draw(bomb->sprite);
}

//------------------------------Beta-------------------------------
class Beta : public Invaders
{
public:
    Beta(Bomb *b);
    virtual void draw(sf::RenderWindow &window) override;
    bool move();
};

Beta::Beta(Bomb *b)
{
    if (!tex.loadFromFile("img/enemy_2.png"))
    {
        std::cout << "Error loading texture" << std::endl;
    }
    sprite.setTexture(tex);
    sprite.setScale(0.4, 0.4);
    bomb = b;
    bomb->sprite.setScale(0.25, 0.25);
    interval = 3;
    timer = 0;
    flag = 0;
    w = 48;
    h = 61.6;
    score_inc = 20;
    bomb->h = 45;
    bomb->w = 45;
}
void Beta::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
    window.draw(bomb->sprite);
}
bool Beta::move()
{
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;
    if (timer >= interval)
    {
        if (flag == 0)
        {
            bomb->sprite.setPosition(sprite.getPosition().x + 10, sprite.getPosition().y);
            flag = 1;
        }
        bomb->move();
    }
    if (bomb->sprite.getPosition().y > 600)
    {
        timer = -interval;
        flag = 0;
        bomb->sprite.setPosition(-100, -100);
        return 1;
    }
    return 0;
}

//---------------------------------Gamma---------------------------
class Gamma : public Invaders
{
public:
    Gamma(Bomb *b);
    virtual void draw(sf::RenderWindow &window) override;
    bool move();
};

Gamma::Gamma(Bomb *b)
{
    if (!tex.loadFromFile("img/enemy_3.png"))
    {
        std::cout << "Error loading texture" << std::endl;
    }
    sprite.setTexture(tex);
    sprite.setScale(0.3, 0.4);
    bomb = b;
    bomb->sprite.setScale(0.25, 0.25);

    interval = 2;
    timer = 0;
    flag = 0;
    w = 48;
    h = 61.6;
    score_inc = 30;
    bomb->h = 45;
    bomb->w = 45;
}
void Gamma::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
    window.draw(bomb->sprite);
}
bool Gamma::move()
{
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;
    if (timer >= interval)
    {
        if (flag == 0)
        {
            bomb->sprite.setPosition(sprite.getPosition().x + 10, sprite.getPosition().y);
            flag = 1;
        }
        bomb->move();
    }
    if (bomb->sprite.getPosition().y > 600)
    {
        flag = 0;
        timer = -interval;
        bomb->sprite.setPosition(-100, -100);
        return 1;
    }
    return 0;
}

#endif