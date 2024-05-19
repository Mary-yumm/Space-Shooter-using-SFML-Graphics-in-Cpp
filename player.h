
#ifndef player_h
#define player_h
#include <iostream>
#include "laser.h"
#include "enemy.h"
#include "addons.h"
using namespace std;
class Player
{
public:
	Texture tex;
	Sprite sprite;
	float speed = 0.75;
	int x, y;
	float w, h;
	static bool flag;
	static float x_dragon;
	static float x_player;
	bool active;
	Addons *addons;
	Laser *laser;
	Player(std::string png_path, Laser *laser);
	void fire(float delta_x, float delta_y);
	void move(std::string s, float &timer, float delay, bool = 0);
	void fire_bombardment(std::string png_path);
	bool anomaly(float delta_x, float delta_y);
	void draw(RenderWindow &window);
	bool destroy_Invader(Enemy **enemy, bool &fire_active, int, int &,int);
	bool destroy_player(Enemy **, int &lives, Player *&p, int);
	bool destroy_player(Bomb *&, int &lives, Player *&p, bool, bool);
	bool destroy_player(Bomb *&, int &, Player *&);
	bool add_addon(Addons *add);
	bool del_addon();
	bool collision_addon(int &, int &);
	void laser_restore(bool &fire_active);
	void powerup_laser();
	bool move_addon(float &timer, int &addonstate);
};
bool Player::flag = 0;
float Player::x_dragon = 0;
float Player::x_player = 0;
bool Player::del_addon(){
	delete addons;
}
bool Player::move_addon(float &timer, int &addonstate)
{
    if (addonstate == 1)
    {
		int f=addons->sprite.getPosition().y;
        if (f > 650)
        {
            addons->sprite.setPosition(0, 800);
            return 1;
        }
        addons->sprite.move(0, addons->speed);
        return 0;
    }
    return 0;
}
void Player::powerup_laser()
{
	delete laser;
	laser = new Laser[7];
	for (int i = 0; i < 7; i++)
	{
		laser[i].x = x + w / 2;
		laser[i].y = y + h / 2;
	}
}
	void Player::laser_restore(bool &fire_active)
	{
		delete laser;
		if (fire_active == 1)
		{
			laser = new Laser("img/sprites/fireaddon.png");
			laser->laser_sprite.setPosition(sprite.getPosition().x + 18, sprite.getPosition().y - 100);
		}
		else
		{
			laser = new Laser("img/PNG/Lasers/laserBlue01.png");
			laser->laser_sprite.setPosition(sprite.getPosition().x + 21, sprite.getPosition().y - 52);
		}
	}
	//----------------------------------------------Player Constructor--------------------------------------------------
	Player::Player(std::string png_path, Laser * laser)
	{
		tex.loadFromFile(png_path); // data(image) loaded through object of class texture
		sprite.setTexture(tex);		// setting loaded texture onto sprite object
		x = 360;
		y = 600; // coordinates of window-screen (defines the position of object on window)
		// 0,0 is at top left extreme | y increases as we move downwards | x increases as we move right
		sprite.setPosition(sf::Vector2f(x, y)); // setting the position of spaceship
		sprite.setScale(0.5, 0.5);				// size of spaceship relative to original size
		this->laser = laser;
		w = 51.5;
		h = 53.5;
		active = 0;
	}

	bool Player::collision_addon(int &addon_state, int &lives)
	{
		bool flag = 0;
		float ax = addons->sprite.getPosition().x;
		float ay = addons->sprite.getPosition().y;
		float px = sprite.getPosition().x;
		float py = sprite.getPosition().y;
		float pw = w;
		float ph = h;
		float aw = addons->w;
		float ah = addons->h;
		if (ay + ah <= py + ph && ax <= px + pw && ay + ah >= py)
		{
			if (ax > px && ay < py)
				flag = 1;
			else if (ax + aw <= px + pw && ax + aw >= px)
				flag = 1;
			else if (py + ph >= ay && ax >= px - aw)
			{
				flag = 1;
			}
		}
		if (flag == 1)
		{
			active = 1;
			addons->sprite.setPosition(-800, -800);
			if (addons->type == "Lives")
			{
				lives++;
				addon_state = 0;
			}
			else if (addons->type == "Danger")
			{
				lives--;
				addon_state = 0;
				laser->laser_sprite.setPosition(x + 21, y - 52);
				sprite.setPosition(x, y);
			}
			return 1;
		}
		return 0;
	}

	bool Player::add_addon(Addons * add)
	{
		addons = add;
		return 1;
	}
	bool Player::destroy_player(Bomb * &bomb, int &lives, Player *&p)
	{
		if (bomb->sprite.getPosition().y >= 570)
		{
			bomb->sprite.setPosition(330, 300);
			flag = 0;
		}
		if (flag == 0)
		{
			int inc = 0;
			x_player = p->sprite.getPosition().x;
			float ly = p->sprite.getPosition().y;
			x_dragon = bomb->sprite.getPosition().x;
			float by = bomb->sprite.getPosition().y;

			flag = 1;
		}
		bomb->sprite.setScale(0.5, 0.5);
		if (x_player > x_dragon)
		{
			if (bomb->sprite.getPosition().y < 570 && bomb->sprite.getPosition().x < x_player)
			{
				bomb->sprite.move(0.5, 0.5);
			}
			else if (bomb->sprite.getPosition().y < 570)
			{
				bomb->sprite.move(0, 0.75);
			}
			else
			{
				flag = 0;
			}
		}
		else if (x_player < x_dragon)
		{
			if (bomb->sprite.getPosition().y < 570 && bomb->sprite.getPosition().x > x_player)
				bomb->sprite.move(-0.5, 0.5);
			else if (bomb->sprite.getPosition().y < 570)
				bomb->sprite.move(0, 0.75);
			else
				flag = 0;
		}
		return 1;
	}
	
	bool Player::destroy_player(Bomb * &bomb, int &lives, Player *&p, bool drag_active, bool mon_active)
	{
		if (drag_active == 1)
		{
			destroy_player(bomb, lives, p);
		}
		bool flag = 0;
		float ax = bomb->sprite.getPosition().x;
		float ay = bomb->sprite.getPosition().y;
		float px = p->sprite.getPosition().x;
		float py = p->sprite.getPosition().y;
		float pw = w;
		float ph = h;
		float aw = bomb->w;
		float ah = bomb->h;

		if (ay + ah <= py + ph && ax <= px + pw && ay + ah >= py)
		{
			if (ax > px && ay < py)
				flag = 1;
			else if (ax + aw <= px + pw && ax + aw >= px)
				flag = 1;
			else if (py + ph >= ay && ax >= px - aw)
			{
				flag = 1;
			}
		}
		if (mon_active == 1)
		{
			if (ax <= px + pw)
			{
				if (ax > px)
				{
					flag = 1;
				}
				else if (ax + aw <= px + pw && ax + aw >= px)
				{
					flag = 1;
				}
			}
		}
		if (flag == 1)
		{
			lives--;
			bomb->sprite.setPosition(-100, -100);
			if (lives >= 0)
			{
				p->sprite.setPosition(x, y);
				laser->laser_sprite.setPosition(x + 21, y - 52);
				if (drag_active == 1)
				{
					bomb->sprite.setPosition(330, 300);
					flag = 0;
				}
				if (mon_active == 1)
				{
					bomb->sprite.setPosition(-200, -200);
					bomb->timer = 0;
				}
			}
			return 1;
		}
		return 0;
	}
	bool Player::destroy_player(Enemy * *enemy, int &lives, Player *&p, int total_invaders)
	{
		bool flag = 0;
		float lx = p->sprite.getPosition().x;
		float ly = p->sprite.getPosition().y;

		float lw = w;
		float lh = h;

		int i = 0;
		while (i < total_invaders)
		{
			float ex = enemy[i]->sprite.getPosition().x;
			float ey = enemy[i]->sprite.getPosition().y;
			float ew = enemy[i]->w;
			float eh = enemy[i]->h;

			if (ly + lh <= ey + eh && lx <= ex + ew && ly + lh >= ey)
			{

				if (lx > ex && ly < ey)
					flag = 1;
				else if (lx + lw <= ex + ew && lx + lw >= ex)
					flag = 1;
				else if (ey + eh >= ly && lx >= ex - lw)
				{
					flag = 1;
				}
			}
			if (flag == 1)
			{
				enemy[i]->sprite.setPosition(0, 800);
				lives--;
				if (lives >= 0)
				{
					p->sprite.setPosition(x, y);
					laser->laser_sprite.setPosition(x + 21, y - 52);
				}
				return 1;
			}
			i++;
		}
		return 0;
	}
	bool Player::destroy_Invader(Enemy * *enemy, bool &fire_active, int total_invaders, int &score,int level)
	{
		// enemy_1=49.6,h=42.4 , enemy2=48,61.6, enemy3=69.2,52.8
		bool flag = 0;
		float lx = laser->laser_sprite.getPosition().x;
		float ly = laser->laser_sprite.getPosition().y;

		float lw = 9;
		float lh = 54;
		if (fire_active == 1)
		{
			lw = 15.5;
			// lh = 109.5;
		}
		int i = 0;
		while (i < total_invaders)
		{
			float ex = enemy[i]->sprite.getPosition().x;
			float ey = enemy[i]->sprite.getPosition().y;
			float ew = enemy[i]->w;
			float eh = enemy[i]->h;

			if (ly + lh <= ey + eh && lx <= ex + ew && ly + lh >= ey)
			{

				if (lx > ex && ly < ey)
					flag = 1;
				else if (lx + lw <= ex + ew && lx + lw >= ex)
					flag = 1;
				else if (ey + eh >= ly && lx >= ex - lw)
				{
					flag = 1;
				}
			}
			if (flag == 1)
			{
				enemy[i]->sprite.setPosition(0, 800);
				if (fire_active != 1)
				{
					float pos_x, pos_y;
					pos_x = sprite.getPosition().x;
					pos_y = sprite.getPosition().y;
					laser->laser_sprite.setPosition(pos_x + 21, pos_y - 52);
				}
				score += ((enemy[i]->score_inc)*level);
				return 1;
			}

			i++;
		}
		return 0;
	}
	//---------------------Adding Addons-------------------------------

	void Player::draw(RenderWindow & window)
	{
		window.draw(laser->laser_sprite);
	}

	//-----------------------------------------Laser Movement as player moves----------------------------------------------
	void Player::fire(float delta_x, float delta_y)
	{
		if (delta_x != 0 || delta_y != 0)
		{
			laser->laser_sprite.move(delta_x, delta_y);
		}
	}

	//------------------------------------------Player y and x both movement---------------------------------------------
	void Player::move(std::string s, float &timer, float delay, bool monster_active)
	{
		float delta_x = 0, delta_y = 0;
		if (s == "l")
			// move the player left
			delta_x = -1;
		else if (s == "r")
			// move the player right
			delta_x = 1;
		if (s == "u" && monster_active == 0)
			delta_y = -1;
		else if (s == "d" && monster_active == 0)
			delta_y = 1;

		delta_x *= speed;
		delta_y *= speed;

		if (!anomaly(delta_x, delta_y))
		{
			sprite.move(delta_x, delta_y); // ftn of sprite class to pass how many units player should be moved
			if (s == "u")
			{
				delta_y = laser->laser_speed - delta_y;
			}
			fire(delta_x, delta_y);
		}
	}

	//----------------------------------------Laser y axis multiple bombardment------------------------------------------
	void Player::fire_bombardment(std::string png_path = "img/PNG/Lasers/laserBlue01.png")
	{

		if (laser->laser_sprite.getPosition().y < 0)
		{
			float pos_x, pos_y;
			pos_x = sprite.getPosition().x;
			pos_y = sprite.getPosition().y;
			if (png_path == "img/sprites/fireaddon.png")
			{
				laser = new Laser(png_path, pos_x + 18, pos_y - 100);
			}
			else
			{
				laser->laser_sprite.setPosition(pos_x + 21, pos_y - 52);
			}
		}
	}
	//----------------------------------------------Player Anomaly---------------------------------------------------------
	bool Player::anomaly(float delta_x, float delta_y)
	{
		if (delta_x + sprite.getPosition().x > 730)
		{
			sprite.setPosition(sf::Vector2f(0, sprite.getPosition().y));
			return 1;
		}
		if (delta_x + sprite.getPosition().x < 0)
		{
			sprite.setPosition(sf::Vector2f(730, sprite.getPosition().y));
			return 1;
		}
		if (delta_y + sprite.getPosition().y > 600)
		{
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x, 0));
			return 1;
		}
		if (delta_y + sprite.getPosition().y < 0)
		{
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x, 580));
			return 1;
		}
		return 0;
	}

#endif