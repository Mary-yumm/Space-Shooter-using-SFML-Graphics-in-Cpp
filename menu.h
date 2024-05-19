#include "game.h"
#ifndef menu_h
#define menu_h
#include <fstream>
class Menu
{
public:
    // add menu attributes here
    Sprite background;
    Texture bg_texture;
    Font font;
    Font font2;
    Font text;
    Menu()
    {
        bg_texture.loadFromFile("img/3.jpg");
        background.setTexture(bg_texture);
        background.setScale(0.4, 0.5);
        if (!font.loadFromFile("fonts/Lobster.otf"))
        {
            std::cerr << "Error loading" << std::endl;
        }
        if (!font2.loadFromFile("fonts/ArianaVioleta.ttf"))
        {
            std::cerr << "Error loading" << std::endl;
        }
        if (!text.loadFromFile("fonts/Calibri.ttf"))
        {
            std::cerr << "Error loading" << std::endl;
        }
    }

    void display_menu()
    {
        int val = 0;
        Game g;
        // display menu screen here
        int choice = start_menu();
        // add functionality of all the menu options here
        switch (choice)
        {
        case 1:
            val = g.start_game();
            break;
        case 2:
            // continue_game();
            break;
        case 3:
            instructions();
            break;
        case 4:
            high_scores(g.scores.filename);
            break;
        case 5:
            exit(0);
        }
        if (val == -1)
            GameOver();
        if (val == 2)
            End_Screen();
    }

    int GameOver()
    {
        RenderWindow window(VideoMode(780, 650), title);

        Text game_name;
        game_name.setFont(font2);
        game_name.setFillColor(Color::White);
        game_name.setOutlineColor(Color::Black);
        game_name.setOutlineThickness(0.3);
        game_name.setCharacterSize(100);
        game_name.setPosition(sf::Vector2f(200, 50));
        game_name.setString("Celestial Havoc");

        Text Menu3;
        Menu3.setFont(font);
        Menu3.setFillColor(Color::White);
        Menu3.setOutlineColor(Color::Black);
        Menu3.setOutlineThickness(0.3);
        Menu3.setCharacterSize(50);
        Menu3.setString("Game Over");

        Text back;
        back.setFont(font);
        back.setFillColor(Color::White);
        back.setOutlineColor(Color::Black);
        back.setOutlineThickness(0.3);
        back.setCharacterSize(30);
        back.setString("Back to Menu");

        sf::Vector2u windowSize = window.getSize();
        game_name.setOrigin(game_name.getLocalBounds().width / 2, game_name.getLocalBounds().height / 2);
        Menu3.setOrigin(back.getLocalBounds().width / 2, back.getLocalBounds().height / 2);
        back.setOrigin(back.getLocalBounds().width / 2, back.getLocalBounds().height / 2);
        Menu3.setPosition(windowSize.x / 2, 250);
        back.setPosition(windowSize.x / 2, 500);
        game_name.setPosition(windowSize.x / 2, 50);

        while (window.isOpen())
        {
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {
                    window.close();
                    return -1;
                }
                if (e.type == sf::Event::MouseButtonPressed)
                {
                    if (e.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                        sf::Vector2f mousePositionFloat(mousePosition.x, mousePosition.y);

                        if (back.getGlobalBounds().contains(mousePositionFloat))
                        {
                            window.close();
                            display_menu();
                        }
                    }
                }
            }
            window.clear(Color::Black);
            window.draw(background);
            window.draw(Menu3);
            window.draw(back);
            window.draw(game_name);
            window.display();
        }
        return 0;
    }

    int start_menu()
    {
        RenderWindow window(VideoMode(780, 650), title);

        Text game_name;
        game_name.setFont(font2);
        game_name.setFillColor(Color::White);
        game_name.setOutlineColor(Color::Black);
        game_name.setOutlineThickness(0.3);
        game_name.setCharacterSize(100);
        game_name.setPosition(sf::Vector2f(200, 50));
        game_name.setString("Celestial Havoc");

        Text start_game;
        start_game.setFont(font);
        start_game.setFillColor(Color::White);
        start_game.setOutlineColor(Color::Black);
        start_game.setOutlineThickness(0.3);
        start_game.setCharacterSize(40);
        start_game.setPosition(sf::Vector2f(250, 200));
        start_game.setString("Start New Game");

        Text continue_game;
        continue_game.setFont(font);
        continue_game.setFillColor(Color::White);
        continue_game.setOutlineColor(Color::Black);
        continue_game.setOutlineThickness(0.3);
        continue_game.setCharacterSize(40);
        continue_game.setString("Continue Game");

        Text instructions;
        instructions.setFont(font);
        instructions.setFillColor(Color::White);
        instructions.setOutlineColor(Color::Black);
        instructions.setOutlineThickness(0.3);
        instructions.setCharacterSize(40);
        instructions.setString("Instructions");

        Text high_scores;
        high_scores.setFont(font);
        high_scores.setFillColor(Color::White);
        high_scores.setOutlineColor(Color::Black);
        high_scores.setOutlineThickness(0.3);
        high_scores.setCharacterSize(40);
        high_scores.setString("High Scores");

        Text quit;
        quit.setFont(font);
        quit.setFillColor(Color::White);
        quit.setOutlineColor(Color::Black);
        quit.setOutlineThickness(0.3);
        quit.setCharacterSize(40);
        quit.setString("Quit");
        sf::Vector2u windowSize = window.getSize();
        game_name.setOrigin(game_name.getLocalBounds().width / 2, game_name.getLocalBounds().height / 2);
        start_game.setOrigin(start_game.getLocalBounds().width / 2, start_game.getLocalBounds().height / 2);
        continue_game.setOrigin(continue_game.getLocalBounds().width / 2, continue_game.getLocalBounds().height / 2);
        instructions.setOrigin(instructions.getLocalBounds().width / 2, instructions.getLocalBounds().height / 2);
        high_scores.setOrigin(high_scores.getLocalBounds().width / 2, high_scores.getLocalBounds().height / 2);
        quit.setOrigin(quit.getLocalBounds().width / 2, quit.getLocalBounds().height / 2);

        // Position the text at the middle of the screen
        game_name.setPosition(windowSize.x / 2, 50);
        start_game.setPosition(windowSize.x / 2, 200);
        continue_game.setPosition(windowSize.x / 2, 300);
        instructions.setPosition(windowSize.x / 2, 400);
        high_scores.setPosition(windowSize.x / 2, 500);
        quit.setPosition(windowSize.x / 2, 600);
        while (window.isOpen())
        {
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {
                    window.close();
                    exit(0);
                }
                if (e.type == sf::Event::MouseButtonPressed)
                {
                    if (e.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                        sf::Vector2f mousePositionFloat(mousePosition.x, mousePosition.y);

                        if (start_game.getGlobalBounds().contains(mousePositionFloat))
                        {
                            return 1;
                        }

                        if (continue_game.getGlobalBounds().contains(mousePositionFloat))
                        {
                            return 2;
                        }

                        if (instructions.getGlobalBounds().contains(mousePositionFloat))
                        {
                            cout << "ins" << endl;
                            return 3;
                        }

                        if (high_scores.getGlobalBounds().contains(mousePositionFloat))
                        {
                            return 4;
                        }

                        if (quit.getGlobalBounds().contains(mousePositionFloat))
                        {
                            return 5;
                        }
                    }
                }
                window.clear(Color::Black);
                window.draw(background);
                window.draw(start_game);
                window.draw(game_name);
                window.draw(continue_game);
                window.draw(instructions);
                window.draw(high_scores);
                window.draw(quit);

                window.display();
            }
        }
        return 0;
    }

    int instructions()
    {
        sf::RenderWindow window(sf::VideoMode(780, 650), "Instructions");
        Text ins;
        ins.setFont(font);
        ins.setFillColor(Color::White);
        ins.setOutlineColor(Color::Black);
        ins.setOutlineThickness(0.3);
        ins.setCharacterSize(40);
        ins.setString("Instructions");

        Text instructions;
        instructions.setFont(text);
        instructions.setFillColor(Color::White);
        instructions.setOutlineColor(Color::Black);
        instructions.setOutlineThickness(0.1);
        instructions.setCharacterSize(20);
        instructions.setStyle(sf::Text::Bold);
        instructions.setString("Press up arrow key for player to go up.\nPress down arrow key for player to go down\nPress right arrow key for player to move rightwards\nPress left arrowkey for player to move leftwards\nPress and hold up and left key together to move the player left-diagonally\nPress and hold up and right key together to move the player right-diagonally\nGet add-ons to have extra features\nDodge the monster and the dragon\nDon't collide with enemies or the bombs coming out of them");

        Text back;
        back.setFont(font);
        back.setFillColor(Color::White);
        back.setOutlineColor(Color::Black);
        back.setOutlineThickness(0.3);
        back.setCharacterSize(40);
        back.setString("Back to menu");

        sf::Vector2u windowSize = window.getSize();
        ins.setOrigin(ins.getLocalBounds().width / 2, ins.getLocalBounds().height / 2);
        instructions.setOrigin(instructions.getLocalBounds().width / 2, instructions.getLocalBounds().height / 2);
        back.setOrigin(back.getLocalBounds().width / 2, back.getLocalBounds().height / 2);
        ins.setPosition(windowSize.x / 2, 50);
        instructions.setPosition(windowSize.x / 2, 300);
        back.setPosition(windowSize.x / 2, 600);

        while (window.isOpen())
        {
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {
                    window.close();
                    exit(0);
                }
                if (e.type == sf::Event::MouseButtonPressed)
                {
                    if (e.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                        sf::Vector2f mousePositionFloat(mousePosition.x, mousePosition.y);

                        if (back.getGlobalBounds().contains(mousePositionFloat))
                        {
                            window.close();
                            display_menu();
                        }
                    }
                }
            }
            window.clear(Color::Black);
            window.draw(background);
            window.draw(ins);
            window.draw(instructions);
            window.draw(back);
            window.display();
        }
        return 0;
    }

    void high_scores(string filename)
    {
        sf::RenderWindow window(sf::VideoMode(780, 650), "High Scores");
        Text high_scores[3];
        int i = 0;
        int y = 200;
        sf::Vector2u windowSize = window.getSize();
        for (i = 0; i < 3; i++)
        {
            high_scores[i].setFont(font);
            high_scores[i].setCharacterSize(30);
            high_scores[i].setOrigin(high_scores[i].getLocalBounds().width / 2, high_scores[i].getLocalBounds().height / 2);
            high_scores[i].setPosition(windowSize.x / 2, y);
            y = y + 100;
        }
        int scores;
        fstream infile;
        infile.open(filename, ios::in);
        i = 0;
        if (infile.is_open())
        {
            while (infile >> scores)
            {
                high_scores[i].setString(std::to_string(scores));
                i++;
            }
        }
        else
        {
            cout << "File not found" << endl;
        }
        int size = i;
        infile.close();
        Text ins;
        ins.setFont(font);
        ins.setFillColor(Color::White);
        ins.setOutlineColor(Color::Black);
        ins.setOutlineThickness(0.3);
        ins.setCharacterSize(40);
        ins.setString("High Scores");

        Text back;
        back.setFont(font);
        back.setFillColor(Color::White);
        back.setOutlineColor(Color::Black);
        back.setOutlineThickness(0.3);
        back.setCharacterSize(40);
        back.setString("Back to menu");

        ins.setOrigin(ins.getLocalBounds().width / 2, ins.getLocalBounds().height / 2);
        back.setOrigin(back.getLocalBounds().width / 2, back.getLocalBounds().height / 2);
        ins.setPosition(windowSize.x / 2, 50);
        back.setPosition(windowSize.x / 2, 600);

        while (window.isOpen())
        {
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {
                    window.close();
                    exit(0);
                }
                if (e.type == sf::Event::MouseButtonPressed)
                {
                    if (e.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                        sf::Vector2f mousePositionFloat(mousePosition.x, mousePosition.y);

                        if (back.getGlobalBounds().contains(mousePositionFloat))
                        {
                            window.close();
                            display_menu();
                        }
                    }
                }
            }
            window.clear(Color::Black);
            window.draw(background);
            window.draw(ins);
            window.draw(back);
            for (i = 0; i < size; i++)
            {
                window.draw(high_scores[i]);
            }
            window.display();
        }
    }

    int End_Screen()
    {
        RenderWindow window(VideoMode(780, 650), title);

        Text game_name;
        game_name.setFont(font2);
        game_name.setFillColor(Color::White);
        game_name.setOutlineColor(Color::Black);
        game_name.setOutlineThickness(0.3);
        game_name.setCharacterSize(100);
        game_name.setPosition(sf::Vector2f(200, 50));
        game_name.setString("Celestial Havoc");

        Text Menu3;
        Menu3.setFont(font);
        Menu3.setFillColor(Color::White);
        Menu3.setOutlineColor(Color::Black);
        Menu3.setOutlineThickness(0.3);
        Menu3.setCharacterSize(50);
        Menu3.setString("You have finished the game :)");

        Text back;
        back.setFont(font);
        back.setFillColor(Color::White);
        back.setOutlineColor(Color::Black);
        back.setOutlineThickness(0.3);
        back.setCharacterSize(30);
        back.setString("Back to Menu");

        sf::Vector2u windowSize = window.getSize();
        game_name.setOrigin(game_name.getLocalBounds().width / 2, game_name.getLocalBounds().height / 2);
        Menu3.setOrigin(back.getLocalBounds().width / 2, back.getLocalBounds().height / 2);
        back.setOrigin(back.getLocalBounds().width / 2, back.getLocalBounds().height / 2);
        Menu3.setPosition(windowSize.x / 2, 250);
        back.setPosition(windowSize.x / 2, 500);
        game_name.setPosition(windowSize.x / 2, 50);

        while (window.isOpen())
        {
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {
                    window.close();
                    return -1;
                }
                if (e.type == sf::Event::MouseButtonPressed)
                {
                    if (e.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                        sf::Vector2f mousePositionFloat(mousePosition.x, mousePosition.y);

                        if (back.getGlobalBounds().contains(mousePositionFloat))
                        {
                            window.close();
                            display_menu();
                        }
                    }
                }
            }
            window.clear(Color::Black);
            window.draw(background);
            window.draw(Menu3);
            window.draw(back);
            window.draw(game_name);
            window.display();
        }
        return 0;
    }
};

#endif