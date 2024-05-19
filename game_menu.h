#include <SFML/Graphics.hpp>
#ifndef game_menu_h
#define game_menu_h
using namespace sf;
class Game_Menu
{
public:
    // add menu attributes here
    Sprite background;
    Texture bg_texture;
    Text Lives_text;
    Text Lives_value;
    Text Score_text;
    Text Score_value;
    Text Level_text;
    Text Level_value;
    Text Phase_text;
    Text Phase_value;
    Text dragon_text;
    Font font;
    Font font2;
    Game_Menu()
    {
        if (!font.loadFromFile("fonts/Oswald-Bold.ttf"))
        {
            std::cerr << "Error loading" << std::endl;
        }
        if (!font2.loadFromFile("fonts/ArianaVioleta.ttf"))
        {
            std::cerr << "Error loading" << std::endl;
        }
        lives();
        score();
        level();
        phase();
        dragon();
    }
    void lives();
    void score();
    void level();
    void phase();
    void dragon();
    void draw(sf::RenderWindow &window);
    void draw_dragon_text(sf::RenderWindow &window);
    int pause_menu(bool& isPaused);
};
void Game_Menu::lives()
{
    int x = 0;
    int y = 690;
    Lives_text.setFont(font);
    Lives_text.setFillColor(Color::White);
    Lives_text.setOutlineColor(Color::Black);
    Lives_text.setOutlineThickness(0.3);
    Lives_text.setCharacterSize(25);
    Lives_text.setPosition(sf::Vector2f(x, y));
    Lives_text.setString(" Lives : ");
    Lives_value.setFont(font);
    Lives_value.setFillColor(Color::White);
    Lives_value.setOutlineColor(Color::Black);
    Lives_value.setOutlineThickness(0.3);
    Lives_value.setCharacterSize(25);
    Lives_value.setPosition(sf::Vector2f(x + 80, y));
}

void Game_Menu::score()
{
    int x = 550;
    int y = 690;
    Score_text.setFont(font);
    Score_text.setFillColor(Color::White);
    Score_text.setOutlineColor(Color::Black);
    Score_text.setOutlineThickness(0.3);
    Score_text.setCharacterSize(25);
    Score_text.setPosition(sf::Vector2f(x, y));
    Score_text.setString(" Score : ");
    Score_value.setFont(font);
    Score_value.setFillColor(Color::White);
    Score_value.setOutlineColor(Color::Black);
    Score_value.setOutlineThickness(0.3);
    Score_value.setCharacterSize(25);
    Score_value.setPosition(sf::Vector2f(x + 90, y));
}

void Game_Menu::level()
{
    int x = 150;
    int y = 690;
    Level_text.setFont(font);
    Level_text.setFillColor(Color::White);
    Level_text.setOutlineColor(Color::Black);
    Level_text.setOutlineThickness(0.3);
    Level_text.setCharacterSize(25);
    Level_text.setPosition(sf::Vector2f(x, y));
    Level_text.setString(" Level : ");
    Level_value.setFont(font);
    Level_value.setFillColor(Color::White);
    Level_value.setOutlineColor(Color::Black);
    Level_value.setOutlineThickness(0.3);
    Level_value.setCharacterSize(25);
    Level_value.setPosition(sf::Vector2f(x + 80, y));
}

void Game_Menu::phase()
{
    int x = 300;
    int y = 690;
    Phase_text.setFont(font);
    Phase_text.setFillColor(Color::White);
    Phase_text.setOutlineColor(Color::Black);
    Phase_text.setOutlineThickness(0.3);
    Phase_text.setCharacterSize(25);
    Phase_text.setPosition(sf::Vector2f(x, y));
    Phase_text.setString(" Phase : ");
    Phase_value.setFont(font);
    Phase_value.setFillColor(Color::White);
    Phase_value.setOutlineColor(Color::Black);
    Phase_value.setOutlineThickness(0.3);
    Phase_value.setCharacterSize(25);
    Phase_value.setPosition(sf::Vector2f(x + 80, y));
}

void Game_Menu::dragon(){

    int x = 300;
    int y = 0;
    dragon_text.setFont(font);
    dragon_text.setFillColor(Color::White);
    dragon_text.setOutlineColor(Color::Black);
    dragon_text.setOutlineThickness(0.3);
    dragon_text.setCharacterSize(25);
    dragon_text.setPosition(sf::Vector2f(x, y));
}

void Game_Menu::draw(sf::RenderWindow &window)
{
    window.draw(Lives_text);
    window.draw(Lives_value);
    window.draw(Score_text);
    window.draw(Score_value);
    window.draw(Level_text);
    window.draw(Level_value);
    window.draw(Phase_text);
    window.draw(Phase_value);
}

void Game_Menu::draw_dragon_text(sf::RenderWindow &window){
    window.draw(dragon_text);
}

int Game_Menu::pause_menu(bool& isPaused)
{
    RenderWindow window(VideoMode(780, 750), "Paused");
    bg_texture.loadFromFile("img/3.jpg");
    background.setTexture(bg_texture);
    background.setScale(0.4, 0.5);
    Text game_name;
    game_name.setFont(font2);
    game_name.setFillColor(Color::White);
    game_name.setOutlineColor(Color::Black);
    game_name.setOutlineThickness(0.3);
    game_name.setCharacterSize(100);
    game_name.setString("Celestial Havoc");

    Text continue_game;
    continue_game.setFont(font);
    continue_game.setFillColor(Color::White);
    continue_game.setOutlineColor(Color::Black);
    continue_game.setOutlineThickness(0.3);
    continue_game.setCharacterSize(40);
    continue_game.setString("Resume");

    Text quit;
    quit.setFont(font);
    quit.setFillColor(Color::White);
    quit.setOutlineColor(Color::Black);
    quit.setOutlineThickness(0.3);
    quit.setCharacterSize(40);
    quit.setString("Quit");
    sf::Vector2u windowSize = window.getSize();
    game_name.setOrigin(game_name.getLocalBounds().width / 2, game_name.getLocalBounds().height / 2);
    continue_game.setOrigin(continue_game.getLocalBounds().width / 2, continue_game.getLocalBounds().height / 2);
    quit.setOrigin(quit.getLocalBounds().width / 2, quit.getLocalBounds().height / 2);

    // Position the text at the middle of the screen
    game_name.setPosition(windowSize.x / 2, 50);
    continue_game.setPosition(windowSize.x / 2, 400);
    quit.setPosition(windowSize.x / 2, 500);
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

                    if (continue_game.getGlobalBounds().contains(mousePositionFloat))
                    {
                        isPaused=0;
                        window.close();
                        return 1;
                    }

                    if (quit.getGlobalBounds().contains(mousePositionFloat))
                    {
                        window.close();
                        exit(0);
                        return 2;
                    }
                }
            }
            window.clear(Color::Black);
            window.draw(background);
            window.draw(game_name);
            window.draw(continue_game);
            window.draw(quit);

            window.display();
        }
    }
    return 0;
}

#endif