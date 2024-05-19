#include <iostream>
#include <time.h>
#include "enemy.h"
#include "bomb.h"
#include "math.h"
#ifndef levels_h
#define levels_h
using namespace std;

class Levels
{
public:
    int lvl;
    int phase;
    int total_invaders;
    Levels(int lvl = 3, int phase = 4);
    bool clear_screen(Enemy **enemy);
    void display_level(Enemy **&enemy, Bomb **bomb);
    void level1_P1_Hollow_Rect(Enemy **&enemy, Bomb **bomb);
    void level1_P2_Hollow_Tri(Enemy **&enemy, Bomb **bomb);
    void level1_P3_Hollow_Cross(Enemy **&enemy, Bomb **bomb);
    void level2_P1_Hollow_Circle(Enemy **&enemy, Bomb **bomb);
    void level2_P2_Hollow_Diamond(Enemy **&enemy, Bomb **bomb);
    void level2_P3_Hollow_Heart(Enemy **&enemy, Bomb **bomb);
    void level3_P1_Filled_Rect(Enemy **&enemy, Bomb **bomb);
    void level3_P2_Filled_Tri(Enemy **&enemy, Bomb **bomb);
    void level3_P3_Filled_Cross(Enemy **&enemy, Bomb **bomb);
    void level3_P4_Filled_Circle(Enemy **&enemy, Bomb **bomb);
    void level3_P5_Filled_Diamond(Enemy **&enemy, Bomb **bomb);
    void level3_P6_Filled_Heart(Enemy **&enemy, Bomb **bomb);
};
Levels::Levels(int lvl, int phase)
{
    this->lvl = lvl;
    this->phase = phase;
}
void Levels::display_level(Enemy **&enemy, Bomb **bomb)
{
    if (lvl == 1 && phase == 1)
    {
        total_invaders = 20;
        level1_P1_Hollow_Rect(enemy, bomb);
    }
    if (lvl == 1 && phase == 2)
    {
        total_invaders = 15;
        level1_P2_Hollow_Tri(enemy, bomb);
    }
    if (lvl == 1 && phase == 3)
    {
        total_invaders = 21;
        level1_P3_Hollow_Cross(enemy, bomb);
    }
    if (lvl == 2 && phase == 1)
    {
        total_invaders = 25;
        level2_P1_Hollow_Circle(enemy, bomb);
    }
    if (lvl == 2 && phase == 2)
    {
        total_invaders = 20;
        level2_P2_Hollow_Diamond(enemy, bomb);
    }
    if (lvl == 2 && phase == 3)
    {
        total_invaders = 14;
        level2_P3_Hollow_Heart(enemy, bomb);
    }
    if (lvl == 3 && phase == 1)
    {
        total_invaders = 32;
        level3_P1_Filled_Rect(enemy, bomb);
    }
    if (lvl == 3 && phase == 2)
    {
        total_invaders = 21;
        level3_P2_Filled_Tri(enemy, bomb);
    }
    if (lvl == 3 && phase == 3)
    {
        total_invaders = 41;
        level3_P3_Filled_Cross(enemy, bomb);
    }
    if (lvl == 3 && phase == 4)
    {
        total_invaders = 70;
        level3_P4_Filled_Circle(enemy, bomb);
    }
    if (lvl == 3 && phase == 5)
    {
        total_invaders = 36;
        level3_P5_Filled_Diamond(enemy, bomb);
    }
    if (lvl == 3 && phase == 6)
    {
        total_invaders = 19;
        level3_P6_Filled_Heart(enemy, bomb);
    }
}

void Levels::level1_P1_Hollow_Rect(Enemy **&enemy, Bomb **bomb)
{
    enemy = new Enemy *[total_invaders];
    bomb = new Bomb *[total_invaders];
    int c = 0;
    while (c < total_invaders)
    {
        bomb[c] = new Bomb;
        c++;
    }

    int random;
    int x = 10;
    int y = 0;
    int k = 0;
    int i = 0, j = 0;
    int space = 0;
    srand(time(0));
    while (i < 4)
    {
        j = 0;
        while (j < 8)
        {
            if (j == 0 || i == 0 || i == 3 || j == 7)
            {
                x = 100 + j * 80;
                y = i * 70;
                random = rand() % 3 + 1;
                switch (random)
                {
                case 1:
                    enemy[k] = new Alpha(bomb[k]);
                    break;
                case 2:
                    enemy[k] = new Beta(bomb[k]);
                    break;
                case 3:
                    enemy[k] = new Gamma(bomb[k]);
                    break;
                }
                enemy[k]->sprite.setPosition(x, y);
                k++;
            }
            j++;
        }
        i++;
    }
}

void Levels::level1_P2_Hollow_Tri(Enemy **&enemy, Bomb **bomb)
{
    enemy = new Enemy *[total_invaders];
    bomb = new Bomb *[total_invaders];
    int c = 0;
    while (c < total_invaders)
    {
        bomb[c] = new Bomb;
        c++;
    }
    int random;
    int x = 10;
    int y = 0;
    int k = 0;
    int i = 5, j = 0;
    int space = 0;
    srand(time(0));
    while (i >= 0)
    {
        j = 0;
        while (j <= i)
        {
            if (j == 0 || i == 0 || j == i || i == 5)
            {
                x = space + 120 + j * 90;
                y = (5 - i) * 70;
                random = rand() % 3 + 1;
                switch (random)
                {
                case 1:
                    enemy[k] = new Alpha(bomb[k]);
                    break;
                case 2:
                    enemy[k] = new Beta(bomb[k]);
                    break;
                case 3:
                    enemy[k] = new Gamma(bomb[k]);
                    break;
                }
                enemy[k]->sprite.setPosition(x, y);
                k++;
            }
            j++;
        }
        space += 50;
        i--;
    }
}

void Levels::level1_P3_Hollow_Cross(Enemy **&enemy, Bomb **bomb)
{
    enemy = new Enemy *[total_invaders];
    bomb = new Bomb *[total_invaders];
    int c = 0;
    while (c < total_invaders)
    {
        bomb[c] = new Bomb;
        c++;
    }
    int random;
    int x = 10;
    int y = 0;
    int k = 0;
    int i = 5, j = 0;
    int space = 0;
    srand(time(0));
    while (i >= 0)
    {
        j = 0;
        while (j <= i)
        {
            if (j == 0 || (j == i && i != 5) || i == 0 || j == 5)
            {
                x = space + 120 + j * 90;
                y = (5 - i) * 40;
                random = rand() % 3 + 1;
                switch (random)
                {
                case 1:
                    enemy[k] = new Alpha(bomb[k]);
                    break;
                case 2:
                    enemy[k] = new Beta(bomb[k]);
                    break;
                case 3:
                    enemy[k] = new Gamma(bomb[k]);
                    break;
                }
                enemy[k]->sprite.setPosition(x, y);
                k++;
            }
            j++;
        }
        space += 50;
        i--;
    }
    y += 40;
    x = x - 50;
    space -= 100;
    i = 1;
    while (i <= 5)
    {
        j = 0;
        while (j <= i)
        {
            if (j == 0 || (j == i && i != 5) || i == 1 || j == 5)
            {
                x = space + 120 + j * 90;
                random = rand() % 3 + 1;
                switch (random)
                {
                case 1:
                    enemy[k] = new Alpha(bomb[k]);
                    break;
                case 2:
                    enemy[k] = new Beta(bomb[k]);
                    break;
                case 3:
                    enemy[k] = new Gamma(bomb[k]);
                    break;
                }
                enemy[k]->sprite.setPosition(x, y);
                k++;
            }
            j++;
        }
        y += 40;
        space -= 50;
        i++;
    }
}

void Levels::level2_P1_Hollow_Circle(Enemy **&enemy, Bomb **bomb)
{

    enemy = new Enemy *[total_invaders];
    bomb = new Bomb *[total_invaders];
    int c = 0;
    while (c < total_invaders)
    {
        bomb[c] = new Bomb;
        c++;
    }
    int random;
    int rad = 200;
    int x_cen = 400;
    int y_cen = 200;
    int k = 0;
    int x, y;
    double pi = 3.14159;
    double radian = 0;
    int angle = 0;
    int space = 360 / total_invaders;
    srand(time(0));
    while (k < total_invaders)
    {
        x = x_cen + rad * cos(angle);
        y = y_cen + rad * sin(angle);
        random = rand() % 3 + 1;
        switch (random)
        {
        case 1:
            enemy[k] = new Alpha(bomb[k]);
            break;
        case 2:
            enemy[k] = new Beta(bomb[k]);
            break;
        case 3:
            enemy[k] = new Gamma(bomb[k]);
            break;
        }
        enemy[k]->sprite.setPosition(x, y);
        k++;
        angle += space;
        radian = angle * pi / 180;
    }
}

void Levels::level2_P2_Hollow_Diamond(Enemy **&enemy, Bomb **bomb)
{
    enemy = new Enemy *[total_invaders];
    bomb = new Bomb *[total_invaders];
    int c = 0;
    while (c < total_invaders)
    {
        bomb[c] = new Bomb;
        c++;
    }
    int random;
    int x = 10;
    int y = 0;
    int k = 0;
    int i = 0, j = 0;
    int space = 250;
    srand(time(0));
    while (i <= 5)
    {
        j = 0;
        while (j <= i)
        {
            if (i == 0 || j == 0 || j == i)
            {
                x = space + 120 + j * 90;
                random = rand() % 3 + 1;
                switch (random)
                {
                case 1:
                    enemy[k] = new Alpha(bomb[k]);
                    break;
                case 2:
                    enemy[k] = new Beta(bomb[k]);
                    break;
                case 3:
                    enemy[k] = new Gamma(bomb[k]);
                    break;
                }
                enemy[k]->sprite.setPosition(x, y);
                k++;
            }
            j++;
        }
        y = y + 40;
        space -= 50;
        i++;
    }

    x = x - 50;
    space = 50;
    i = 4;
    while (i >= 0)
    {
        j = 0;
        while (j <= i)
        {
            if (j == 0 || j == i)
            {
                x = space + 120 + j * 90;
                random = rand() % 3 + 1;
                switch (random)
                {
                case 1:
                    enemy[k] = new Alpha(bomb[k]);
                    break;
                case 2:
                    enemy[k] = new Beta(bomb[k]);
                    break;
                case 3:
                    enemy[k] = new Gamma(bomb[k]);
                    break;
                }
                enemy[k]->sprite.setPosition(x, y);
                k++;
            }
            j++;
        }
        y += 40;
        space += 50;
        i--;
    }
}

void Levels::level2_P3_Hollow_Heart(Enemy **&enemy, Bomb **bomb)
{
    enemy = new Enemy *[total_invaders];
    bomb = new Bomb *[total_invaders];
    int c = 0;
    while (c < total_invaders)
    {
        bomb[c] = new Bomb;
        c++;
    }
    int random;
    int x = 10;
    int y = 0;
    int k = 0;
    int i = 5, j = 0;
    int space = 0;
    srand(time(0));
    while (i >= 0)
    {
        j = 0;
        while (j <= i)
        {
            if (j == 0 || i == 0 || j == i || i == 5 || (i == 4 && j == 2))
            {
                if ((j == 0 && i == 5) || (i == 5 && j == i))
                {
                    j++;
                    continue;
                }
                x = space + 120 + j * 90;
                y = (5 - i) * 70;
                random = rand() % 3 + 1;
                switch (random)
                {
                case 1:
                    enemy[k] = new Alpha(bomb[k]);
                    break;
                case 2:
                    enemy[k] = new Beta(bomb[k]);
                    break;
                case 3:
                    enemy[k] = new Gamma(bomb[k]);
                    break;
                }
                enemy[k]->sprite.setPosition(x, y);
                k++;
            }
            j++;
        }
        space += 50;
        i--;
    }
}

void Levels::level3_P1_Filled_Rect(Enemy **&enemy, Bomb **bomb)
{
    enemy = new Enemy *[total_invaders];
    bomb = new Bomb *[total_invaders];
    int c = 0;
    while (c < total_invaders)
    {
        bomb[c] = new Bomb;
        c++;
    }
    int random;
    int x = 10;
    int y = 0;
    int k = 0;
    int i = 0, j = 0;
    srand(time(0));
    while (i < 4)
    {
        j = 0;
        while (j < 8)
        {
            x = 100 + j * 80;
            y = i * 70;
            random = rand() % 3 + 1;
            switch (random)
            {
            case 1:
                enemy[k] = new Alpha(bomb[k]);
                break;
            case 2:
                enemy[k] = new Beta(bomb[k]);
                break;
            case 3:
                enemy[k] = new Gamma(bomb[k]);
                break;
            }
            enemy[k]->sprite.setPosition(x, y);
            k++;

            j++;
        }
        i++;
    }
}

void Levels::level3_P2_Filled_Tri(Enemy **&enemy, Bomb **bomb)
{
    enemy = new Enemy *[total_invaders];
    bomb = new Bomb *[total_invaders];
    int c = 0;
    while (c < total_invaders)
    {
        bomb[c] = new Bomb;
        c++;
    }
    int random;
    int x = 10;
    int y = 0;
    int k = 0;
    int i = 5, j = 0;
    int space = 0;
    srand(time(0));
    while (i >= 0)
    {
        j = 0;
        while (j <= i)
        {
            x = space + 120 + j * 90;
            y = (5 - i) * 70;
            random = rand() % 3 + 1;
            switch (random)
            {
            case 1:
                enemy[k] = new Alpha(bomb[k]);
                break;
            case 2:
                enemy[k] = new Beta(bomb[k]);
                break;
            case 3:
                enemy[k] = new Gamma(bomb[k]);
                break;
            }
            enemy[k]->sprite.setPosition(x, y);
            k++;
            j++;
        }
        space += 48;
        i--;
    }
}

void Levels::level3_P3_Filled_Cross(Enemy **&enemy, Bomb **bomb)
{
    enemy = new Enemy *[total_invaders];
    bomb = new Bomb *[total_invaders];
    int c = 0;
    while (c < total_invaders)
    {
        bomb[c] = new Bomb;
        c++;
    }
    int random;
    int x = 10;
    int y = 0;
    int k = 0;
    int i = 5, j = 0;
    int space = 0;
    srand(time(0));
    while (i >= 0)
    {
        j = 0;
        while (j <= i)
        {
            x = space + 120 + j * 90;
            y = (5 - i) * 40;
            random = rand() % 3 + 1;
            switch (random)
            {
            case 1:
                enemy[k] = new Alpha(bomb[k]);
                break;
            case 2:
                enemy[k] = new Beta(bomb[k]);
                break;
            case 3:
                enemy[k] = new Gamma(bomb[k]);
                break;
            }
            enemy[k]->sprite.setPosition(x, y);
            k++;
            j++;
        }
        space += 50;
        i--;
    }
    y += 40;
    x = x - 50;
    space -= 100;
    i = 1;
    while (i <= 5)
    {
        j = 0;
        while (j <= i)
        {
            x = space + 120 + j * 90;
            random = rand() % 3 + 1;
            switch (random)
            {
            case 1:
                enemy[k] = new Alpha(bomb[k]);
                break;
            case 2:
                enemy[k] = new Beta(bomb[k]);
                break;
            case 3:
                enemy[k] = new Gamma(bomb[k]);
                break;
            }
            enemy[k]->sprite.setPosition(x, y);
            k++;

            j++;
            cout << k << endl;
        }
        y += 40;
        space -= 50;
        i++;
    }
}

void Levels::level3_P4_Filled_Circle(Enemy **&enemy, Bomb **bomb)
{
    enemy = new Enemy *[total_invaders];
    bomb = new Bomb *[total_invaders];
    int c = 0;
    while (c < total_invaders)
    {
        bomb[c] = new Bomb;
        c++;
    }
    int random;
    int rad = 200;
    int x_cen = 400;
    int y_cen = 200;
    int k = 0;
    int x, y;
    double pi = 3.14159;
    double radian = 0;
    int angle = 0;
    int layer1 = 25;
    float space = 360 / layer1;
    srand(time(0));
    while (k < layer1)
    {
        x = x_cen + rad * cos(angle);
        y = y_cen + rad * sin(angle);
        random = rand() % 3 + 1;
        switch (random)
        {
        case 1:
            enemy[k] = new Alpha(bomb[k]);
            break;
        case 2:
            enemy[k] = new Beta(bomb[k]);
            break;
        case 3:
            enemy[k] = new Gamma(bomb[k]);
            break;
        }
        enemy[k]->sprite.setPosition(x, y);
        k++;
        angle += space;
        radian = angle * pi / 180;
    }
    rad = 150;
    angle = 0;
    int layer2 = 20;
    space = 360 / (layer2);
    while (k < layer1 + layer2)
    {
        x = x_cen + rad * cos(angle);
        y = y_cen + rad * sin(angle);
        random = rand() % 3 + 1;
        switch (random)
        {
        case 1:
            enemy[k] = new Alpha(bomb[k]);
            break;
        case 2:
            enemy[k] = new Beta(bomb[k]);
            break;
        case 3:
            enemy[k] = new Gamma(bomb[k]);
            break;
        }
        enemy[k]->sprite.setPosition(x, y);
        k++;
        angle += space;
        radian = angle * pi / 180;
    }
    rad = 100;
    angle = 0;
    int layer3 = 15;
    space = 360 / (layer3);
    while (k < layer1 + layer2 + layer3)
    {
        x = x_cen + rad * cos(angle);
        y = y_cen + rad * sin(angle);
        random = rand() % 3 + 1;
        switch (random)
        {
        case 1:
            enemy[k] = new Alpha(bomb[k]);
            break;
        case 2:
            enemy[k] = new Beta(bomb[k]);
            break;
        case 3:
            enemy[k] = new Gamma(bomb[k]);
            break;
        }
        enemy[k]->sprite.setPosition(x, y);
        k++;
        angle += space;
        radian = angle * pi / 180;
    }
    rad = 50;
    angle = 0;
    int layer4 = total_invaders - layer1 - layer2 - layer3;
    space = 360 / (layer4);
    while (k < total_invaders)
    {
        x = x_cen + rad * cos(angle);
        y = y_cen + rad * sin(angle);
        random = rand() % 3 + 1;
        switch (random)
        {
        case 1:
            enemy[k] = new Alpha(bomb[k]);
            break;
        case 2:
            enemy[k] = new Beta(bomb[k]);
            break;
        case 3:
            enemy[k] = new Gamma(bomb[k]);
            break;
        }
        enemy[k]->sprite.setPosition(x, y);
        k++;
        angle += space;
        radian = angle * pi / 180;
    }
}

void Levels::level3_P5_Filled_Diamond(Enemy **&enemy, Bomb **bomb)
{
    enemy = new Enemy *[total_invaders];
    bomb = new Bomb *[total_invaders];
    int c = 0;
    while (c < total_invaders)
    {
        bomb[c] = new Bomb;
        c++;
    }
    int random;
    int x = 10;
    int y = 0;
    int k = 0;
    int i = 0, j = 0;
    int space = 250;
    srand(time(0));
    while (i <= 5)
    {
        j = 0;
        while (j <= i)
        {
            x = space + 120 + j * 90;
            random = rand() % 3 + 1;
            switch (random)
            {
            case 1:
                enemy[k] = new Alpha(bomb[k]);
                break;
            case 2:
                enemy[k] = new Beta(bomb[k]);
                break;
            case 3:
                enemy[k] = new Gamma(bomb[k]);
                break;
            }
            enemy[k]->sprite.setPosition(x, y);
            k++;
            j++;
        }
        y = y + 40;
        space -= 50;
        i++;
    }
    x = x - 50;
    space = 50;
    i = 4;
    while (i >= 0)
    {
        j = 0;
        while (j <= i)
        {
            x = space + 120 + j * 90;
            random = rand() % 3 + 1;
            switch (random)
            {
            case 1:
                enemy[k] = new Alpha(bomb[k]);
                break;
            case 2:
                enemy[k] = new Beta(bomb[k]);
                break;
            case 3:
                enemy[k] = new Gamma(bomb[k]);
                break;
            }
            enemy[k]->sprite.setPosition(x, y);
            k++;
            j++;
        }
        y += 40;
        space += 50;
        i--;
    }
}

void Levels::level3_P6_Filled_Heart(Enemy **&enemy, Bomb **bomb)
{
    enemy = new Enemy *[total_invaders];
    bomb = new Bomb *[total_invaders];
    int c = 0;
    while (c < total_invaders)
    {
        bomb[c] = new Bomb;
        c++;
    }
    int random;
    int x = 10;
    int y = 0;
    int k = 0;
    int i = 5, j = 0;
    int space = 0;
    srand(time(0));
    while (i >= 0)
    {
        j = 0;
        while (j <= i)
        {
            if ((j == 0 && i == 5) || (i == 5 && j == i))
            {
                j++;
                continue;
            }
            x = space + 120 + j * 90;
            y = (5 - i) * 70;
            random = rand() % 3 + 1;
            switch (random)
            {
            case 1:
                enemy[k] = new Alpha(bomb[k]);
                break;
            case 2:
                enemy[k] = new Beta(bomb[k]);
                break;
            case 3:
                enemy[k] = new Gamma(bomb[k]);
                break;
            }
            enemy[k]->sprite.setPosition(x, y);
            k++;

            j++;
        }
        space += 48;
        i--;
    }
}

bool Levels::clear_screen(Enemy **enemy)
{
    int i = 0;
    for (i = 0; i < total_invaders; i++)
    {
        float x = enemy[i]->sprite.getPosition().x;
        float y = enemy[i]->sprite.getPosition().y;
        if (x >= 0 && y >= 0 && x <= 730 && y <= 600)
        {
            return false;
        }
    }
    return true;
}
#endif