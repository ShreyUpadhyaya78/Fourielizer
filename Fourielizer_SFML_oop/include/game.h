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

    //Game objects
    sf::CircleShape primaryCircle;
   // sf::Vertex line[] = { sf::Vertex(sf::Vector2f(2, 10)), sf::Vertex(sf::Vector2f(400, 100)) };
    //sf::VertexArray line(sf::Triangles, 3);

    //Private functions
    void initVariables();
    void initWindow();
    void initShape();
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
    void draw();

};

#endif // GAME_H
