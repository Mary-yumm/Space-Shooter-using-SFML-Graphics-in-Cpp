
#include <SFML/Graphics.hpp>
#include <time.h>
#include "player.h"
#include "levels.h"
#include "laser.h"
#include "addons.h"
#include "enemy.h"
#include "bomb.h"
#include "score.h"
#ifndef game_h
#define game_h
#include "game_menu.h"
const char title[] = "Space Shooter ";
using namespace sf;
class Game
{
public:
    Sprite background;  // Game background sprite
    Texture bg_texture; // whole background
    Player *p;          // player spaceship
    Game_Menu menu_game;
    Score scores;
    int lives;
    int score;
    Levels level;
    Bomb **bomb;
    Sprite sprite;
    Texture tex;
    Enemy **enemy;
    Enemy *enemies;
    Game();
    int start_game();
    ~Game();
};
Game::Game()
{
    // tex.loadFromFile("img/sprites/laserbeam2.png");
    // sprite.setTexture(tex);
    // sprite.setPosition(412, 0);
    // sprite.setScale(1, 3.2);
    // cout << "Origin = " << sprite.getOrigin().x << " " << sprite.getOrigin().y << endl;
    // FloatRect spriteBounds = sprite.getGlobalBounds();
    // float spriteWidth = spriteBounds.width;
    // float spriteHeight = spriteBounds.height;
    // cout << "width = " << spriteWidth << endl;
    // cout << "height = " << spriteHeight << endl;
    score = 0;
    p = new Player("img/player_ship.png", new Laser); // constructor from player.h
    bg_texture.loadFromFile("img/3.jpg");             // loading the background using texture object
    background.setTexture(bg_texture);                // setting loaded texture onto sprite object
    background.setScale(0.4, 0.5);
    lives = 5;
}
Game::~Game()
{
    delete p;
    scores.store_score(score);
    score = 0;
}

int Game::start_game()
{
    int phase = 0;
    int clear = 1;
    srand(time(0));
    RenderWindow window(VideoMode(780, 750), title); // width,height of total window
    Clock clock;
    level.display_level(enemy, bomb);
    float timer = 0;
    float enemies_timer = 0;
    float enemies_delay = 60;
    bool monster_active = 0;
    bool dragon_active = 0;
    float bomb_timer = 0;
    float delay = 0.4;
    int destroy = 0;
    bool flag = 0;
    float distance = 300.0f;
    int addon_state = 0;
    float addon_timer = 0;
    float fire_timer = 0;
    bool fire_active = 0;
    float powerup_timer = 0;
    bool powerup_active = 0;
    int *invaders_posx;
    int *invaders_posy;
    int invaders_total = 0;
    bool diag_left = 0;
    bool diag_right = 0;
    bool diag_enable = 0;
    bool laser_diag = 0;
    bool isPaused = 0;
    bool powerup_start = 0;
    sf::Vector2u windowSize = window.getSize();

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        Event e;
        while (window.pollEvent(e)) // State of event, initially 1
        {
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
            {
                window.close(); // close the game
                exit(0);
            }
            if (e.type == sf::Event::KeyPressed)
            {
                if (e.key.code == sf::Keyboard::P)
                {
                    isPaused = !isPaused;
                    if (isPaused == 1)
                    {
                        menu_game.pause_menu(isPaused);
                    }
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Space))
            {
                if (diag_left == 1 || diag_right == 1)
                {
                    diag_enable = 0;
                    int x = p->sprite.getPosition().x;
                    int y = p->sprite.getPosition().y;

                        diag_left = 0;
                        diag_right = 0;
                        delete p;
                        if (fire_active == 1)
                            p = new Player("img/player_ship.png", new Laser("img/sprites/fireaddon.png", x + 18, y - 100));
                        else
                            p = new Player("img/player_ship.png", new Laser("img/PNG/Lasers/laserBlue01.png", x + 21, y - 52));

                    p->sprite.setPosition(x, y);
                }
            }
        }
        if (isPaused == 1)
        {
        }
        bool left = false;
        bool right = false;
        bool up = false;
        if (!isPaused)
        {
            if (Keyboard::isKeyPressed(Keyboard::Left)) // If left key is pressed
            {
                p->move("l", timer, delay);
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                p->move("r", timer, delay);
            }
            if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                p->move("u", timer, delay, monster_active);
            }
            if (Keyboard::isKeyPressed(Keyboard::Down))
                p->move("d", timer, delay, monster_active);
            if (Keyboard::isKeyPressed(Keyboard::D))
            {
                if (diag_enable == 0)
                {
                    int x = p->sprite.getPosition().x;
                    int y = p->sprite.getPosition().y;
                    delete p;
                    if (fire_active == 1)
                        p = new Player("img/sprites/player_anti.png", new Laser("img/sprites/fireaddon_anti.png", x + 18, y - 100));
                    else
                        p = new Player("img/sprites/player_anti.png", new Laser("img/sprites/laser_anti.png", x + 21, y + 0));
                    p->sprite.setPosition(x, y);
                    diag_left = 1;
                    diag_enable = 1;
                }
            }
            else if (Keyboard::isKeyPressed(Keyboard::F))
            {
                if (diag_enable == 0)
                {
                    int x = p->sprite.getPosition().x;
                    int y = p->sprite.getPosition().y;
                    delete p;
                    if (fire_active == 1)
                        p = new Player("img/sprites/player_clock.png", new Laser("img/sprites/fireaddon_clock.png", x + 18, y - 100));
                    else
                        p = new Player("img/sprites/player_clock.png", new Laser("img/sprites/laser_clock.png", x + 21, y - 30));
                    p->sprite.setPosition(x, y);
                    diag_right = 1;
                    diag_enable = 1;
                }
            }
            timer += time;
            enemies_timer += time;
            bomb_timer += time;
            addon_timer += time;
            enemies_timer += time;
            ////////////////////////////////////////////////
            /////  Call your functions here            ////
            //////////////////////////////////////////////
          
            if (enemies_timer >= enemies_delay && flag == 0)
            {
                int i = 0;
                invaders_posx = new int[level.total_invaders];
                invaders_posy = new int[level.total_invaders];
                flag = 1;
                invaders_total = level.total_invaders;
                while (i < level.total_invaders)
                {
                    invaders_posx[i] = enemy[i]->sprite.getPosition().x;
                    invaders_posy[i] = enemy[i]->sprite.getPosition().y;
                    i++;
                }
                for (int i = 0; i < level.total_invaders; i++)
                {
                    delete enemy[i];
                }
                delete[] enemy;
                
                bomb = new Bomb *[1];
                int random;
                random = rand() % 2 + 1;
                if (random == 1)
                {
                    bomb[0] = new Bomb("img/sprites/dragfire2.png");
                    enemy = new Enemy *[1];
                    enemy[0] = new Dragon(bomb[0]);
                    dragon_active = 1;
                    p->sprite.setPosition(p->sprite.getPosition().x, 600);
                }
                else
                {
                    bomb[0] = new Bomb("img/sprites/laserbeam2.png");
                    enemy = new Enemy *[1];
                    enemy[0] = new Monster(bomb[0]);
                    monster_active = 1;
                    p->sprite.setPosition(p->sprite.getPosition().x, 600);
                }

                level.total_invaders = 1;
            }
            if (enemies_timer >= 80 && flag == 1)
            {
                if(monster_active==1)
                score+=40;
                if(dragon_active==1)
                score+=50;
                int i = 0;
                delete enemy[0];
                delete[] enemy;
                level.display_level(enemy, bomb);
                level.total_invaders = invaders_total;
                while (i < level.total_invaders)
                {
                    enemy[i]->sprite.setPosition(invaders_posx[i], invaders_posy[i]);
                    i++;
                }
                delete[] invaders_posx;
                delete[] invaders_posy;
                enemies_timer = 0;
                flag = 0;
                monster_active = 0;
                dragon_active = 0;
            }
            menu_game.Score_value.setString(std::__cxx11::to_string(score));
            menu_game.Lives_value.setString(std::__cxx11::to_string(lives));
            if (dragon_active == 1)
            {
                menu_game.dragon_text.setString("Dodge the Dragon");
            }
            else if (monster_active == 1)
            {
                menu_game.dragon_text.setString("Dodge the Monster");
            }
            menu_game.Level_value.setString(std::__cxx11::to_string(level.lvl));
            menu_game.Phase_value.setString(std::__cxx11::to_string(level.phase));
            //----------------------Levels---------------------------------
            if (monster_active != 1 && dragon_active != 1)
            {
                if (level.clear_screen(enemy))
                {
                    for (int i = 0; i < level.total_invaders; i++)
                    {
                        delete enemy[i];
                    }
                    delete[] enemy;
                    if (level.lvl != 3)
                    {
                        if (level.phase < 3)
                            level.phase++;
                        else
                        {
                            level.phase = 1;
                            level.lvl++;
                        
                        }
                    }
                    else
                    {

                        level.phase++;
                        if (phase == 7)
                            return 2;
                    }
                    level.display_level(enemy, bomb);
                }
            }
            //-------------------------Fire bombardment---------------------
            if (fire_active == 1 || powerup_active == 1)
            {
                if (fire_timer < 5 && p->addons->type == "Fire")
                {
                    fire_timer += time;
                    if (diag_left == 1)
                        p->fire_bombardment("img/sprites/fireaddon_anti.png");
                    else if (diag_right == 1)
                        p->fire_bombardment("img/sprites/fireaddon_clock.png");
                    else
                        p->fire_bombardment("img/sprites/fireaddon.png");
                    p->laser->move(diag_left, diag_right);
                }
                else if (fire_timer > 5 && p->addons->type == "Fire")
                {
                    addon_state = fire_timer = fire_active = addon_timer = 0;
                    delete p->addons;
                }
                else if (powerup_timer < 5 && p->addons->type == "Power Up")
                {
                    if (powerup_start == 0)
                    {
                        powerup_start = 1;
                        p->powerup_laser();
                    }
                    powerup_timer += time;
                    p->fire_bombardment();
                    p->laser->move(diag_left, diag_right);
                }
                else if (powerup_timer > 5 && p->addons->type == "Power Up")
                {
                    addon_state = powerup_timer = powerup_active = addon_timer = 0;
                    delete p->addons;
                    powerup_start = 0;
                }
            }
            else
            {
                if (diag_left == 1 || diag_right == 1)
                {
                    if (p->laser->laser_sprite.getPosition().y < 0)
                    {
                        p->laser->laser_sprite.setPosition(p->sprite.getPosition().x, p->sprite.getPosition().y);
                    }
                }
                else
                    p->fire_bombardment();
                p->laser->move(diag_left, diag_right);
            }
            //-----------------------Bomb move and player destruction---------
            for (int i = 0; i < level.total_invaders; i++)
            {
                if (enemy[i] != NULL)
                {
                    (enemy[i]->move());

                    if (p->destroy_player(enemy[i]->bomb, lives, p, dragon_active, monster_active))
                    {
                        if (lives < 0)
                        {
                            return -1;
                        }
                    }
                }
            }
            //------------------------------ADDONS-----------------------------

            if (timer > 10 && addon_state == 0)
            {
                addon_state = 1;
                int random = rand() % 4 + 1;
                // int random = 2;
                if (random == 1)
                    p->add_addon(new PowerUp());
                else if (random == 2)
                    p->add_addon(new Fire());
                else if (random == 3)
                    p->add_addon(new Lives());
                else if (random == 4)
                    p->add_addon(new Danger());
            }
            if(addon_state==1){
            if (p->move_addon(addon_timer, addon_state))
            {
                if (p->addons->type == "Danger")
                {
                    score += 5;
                    p->del_addon();
                    addon_timer = 0;
                    addon_state = 0;
                }
                else
                {
                    p->del_addon();
                    addon_timer = 0;
                    addon_state = 0;
                }
            }
            }
            if (addon_state == 1 && fire_active == 0 && powerup_active == 0)
            {
                if (p->collision_addon(addon_state, lives))
                {
                    if (p->addons->type == "Fire")
                    {
                        fire_timer = 0;
                        fire_active = 1;
                    }
                    else if (p->addons->type == "Power Up")
                    {
                        powerup_active = 1;
                        powerup_timer = 0;
                    }
                }
            }
            //-------------------------Destruction------------------------------
            (p->destroy_Invader(enemy, fire_active, level.total_invaders, score,level.lvl));

            if (p->destroy_player(enemy, lives, p, level.total_invaders))
            {
                if (lives < 0)
                {
                    return -1;
                }
            }
        }
        //-----------------------------DRAW--------------------------------
        window.clear(Color::Black);
        window.draw(background);

        window.draw(p->sprite);
        p->draw(window);


        for (int i = 0; i < level.total_invaders; i++)
        {
            if (enemy[i] != NULL)
            {
                enemy[i]->draw(window);
            }
        }

        if (addon_state == 1)
            p->addons->draw(window);

        menu_game.draw(window);
        if (monster_active == 1 || dragon_active == 1)
        {
            menu_game.draw_dragon_text(window);
        }
        window.display();
    }
    return 0;
}

#endif
