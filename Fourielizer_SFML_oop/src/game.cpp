#include "game.h"

//Private functions
void Game::initVariables()
{
    this->window = nullptr;
}
void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    window = new sf::RenderWindow(this->videoMode, "Fourielizer", sf::Style::Close | sf::Style::Resize);


    this->window->setFramerateLimit(60);
}
void Game::initShape(){
    float radius = 100.f;
    this->primaryCircle.setRadius(radius);
    this->primaryCircle.setFillColor(sf::Color::Transparent);
    this->primaryCircle.setOutlineThickness(1.f);
    this->primaryCircle.setPosition(sf::Vector2f(100.f, 200.f));

    /*this->line[0].position = sf::Vector2f(100.f+2*radius, 200.f+radius);
    this->line[1].position = sf::Vector2f(100.f+2*radius+300, 200.f+radius);
    this->line[2].position = sf::Vector2f(100.f+2*radius+300, 200.f+radius+100.f);*/
}

//Constructors and Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initShape();
}

Game::~Game()
{
    delete this->window;
}


//Accessors
const bool Game::isWindowOpen() const
{
    return this->window->isOpen();
}

//Functions
void Game::pollEvents(){
    // check all the window's events that were triggered since the last iteration of the loop
    while (this->window->pollEvent(this->event))
    {
        // "close requested" event: we close the window
        /*if (event.type == sf::Event::Closed | (sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            window.close();*/
        //if can also be used but switch is also widely used as:
        switch (this->event.type){
            //window closed
        case sf::Event::Closed:
            this->window->close();
        case sf::Event::KeyPressed:
            if (this->event.key.code == sf::Keyboard::Escape)
                this->window->close();
        case sf::Event::Resized:
            {
                //window.setSize(sf::Vector2u(event.size.width, event.size.height));
            }
        default:
            continue;
            }
        }
}

void Game::update(){ //This is where all the logic behind the stuff is
    this->pollEvents();

    //Update mouse position
    std::cout<<"Mouse Position: "<<sf::Mouse::getPosition().x<<","<<sf::Mouse::getPosition().y<<std::endl; //relative to the screen
    std::cout<<"Mouse Position Relative to the Window: "<<sf::Mouse::getPosition(*this->window).x<<","<<sf::Mouse::getPosition(*this->window).y<<std::endl; //relative to the screen


}

void Game::render(){ //This is where all the display stuff happens
    this->window->clear();

    //Draw game objects
    this->window->draw(this->primaryCircle);
    //this->window.draw(line, 2, sf::Lines)
    this->window->display(); //Tell the app that it is done drawing
}

void Game::draw(){ //this is where all the drawing will happen


}
