#include "game.h"

//Private functions
void Game::initVariables(){
    this->window = nullptr;
    rectHeight = 75.f;
    rectWidth = 150.f;
}
void Game::initWindow(){
    this->videoMode.height = 768;
    this->videoMode.width = 1366;
    window = new sf::RenderWindow(this->videoMode, "Fourielizer", sf::Style::Close | sf::Style::Resize);


    this->window->setFramerateLimit(60);
}
void Game::initShape(){
    for (int i = 0 ; i<4 ; ++i){
        rect[i].setSize(sf::Vector2f(rectWidth, rectHeight));
        rect[i].setFillColor(sf::Color::Cyan);
    }
    rect[0].setPosition(50, 300);
    rect[1].setPosition(1166, 300);
    rect[2].setPosition(50, 450);
    rect[3].setPosition(1166, 450);

}
void Game::initText(){
    //Setting the text object and font
    sf::Font font;
    try{
        if (!(font.loadFromFile("arial.ttf"))) throw "Bad Font Load\n";
    }
    catch(const char* err){
        std::cerr<< "[ERROR]: " << err;
    }
    sf::Text text;
    text.setFont(font);
    text.setString("WELCOME TO FOURIELIZER");
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setCharacterSize(25);
    text.setPosition(sf::Vector2f(200, 50));
}


//Constructors and Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initShape();
    this->initText();
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

    if ( sf::Mouse::getPosition(*this->window).x > rect[0].getPosition().x && sf::Mouse::getPosition(*this->window).x < (rect[0].getPosition().x + 150) && sf::Mouse::getPosition(*this->window).y > rect[0].getPosition().y && (sf::Mouse::getPosition(*this->window).y < rect[0].getPosition().y + 75) && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left ){
        std::cout<<"Mouse Clicked on 1st rect\n";
    }
    if ( sf::Mouse::getPosition(*this->window).x > rect[1].getPosition().x && sf::Mouse::getPosition(*this->window).x < (rect[1].getPosition().x + 150) && sf::Mouse::getPosition(*this->window).y > rect[1].getPosition().y && (sf::Mouse::getPosition(*this->window).y < rect[1].getPosition().y + 75) && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left ){
        std::cout<<"Mouse Clicked on 2nd rect\n";
    }
    if ( sf::Mouse::getPosition(*this->window).x > rect[2].getPosition().x && sf::Mouse::getPosition(*this->window).x < (rect[2].getPosition().x + 150) && sf::Mouse::getPosition(*this->window).y > rect[2].getPosition().y && (sf::Mouse::getPosition(*this->window).y < rect[2].getPosition().y + 75) && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left ){
        std::cout<<"Mouse Clicked on 3rd rect\n";
    }
    if ( sf::Mouse::getPosition(*this->window).x > rect[3].getPosition().x && sf::Mouse::getPosition(*this->window).x < (rect[3].getPosition().x + 150) && sf::Mouse::getPosition(*this->window).y > rect[3].getPosition().y && (sf::Mouse::getPosition(*this->window).y < rect[3].getPosition().y + 75) && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left ){
        std::cout<<"Mouse Clicked on 4th rect\n";
    }

    //sf::Mouse::getPosition(*this->window).y//relative to the screen

    //Update mouse position
    //std::cout<<"Mouse Position: "<<sf::Mouse::getPosition().x<<","<<sf::Mouse::getPosition().y<<std::endl; //relative to the screen


}

void Game::render(){ //This is where all the display stuff happens
    this->window->clear();

    //Draw game objects
    this->window->draw(text);
    for (int i = 0 ; i<4 ; ++i){
        this->window->draw(rect[i]);
    }

    this->window->display(); //Tell the app that it is done drawing
}

