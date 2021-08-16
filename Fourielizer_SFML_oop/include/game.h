#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<iostream>

class Game
{
private:
    //Variables
    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode;
    float rectHeight, rectWidth;
    float paddingx, paddingy;

    //Game objects
    sf::Font font;
    sf::Text text;
    sf::RectangleShape rect[4];
    sf::Font fontInRect;
    sf::Text textInRect[4];

    //Private functions
    void initVariables();
    void initWindow();
    void initShape();
    void initText();

protected:

public:
    //Constructors and Destructors
    Game();
    virtual ~Game();

    //Accessors
    const bool isWindowOpen() const;

    //Functions
    void pollEvents();
    void update();
    void render();

};

#endif // GAME_H
