#include "game.h"

//Private functions
void Game::initVariables(){
    this->window = nullptr;
    rectHeight = 150.f;
    rectWidth = 400.f;
    paddingx = 45.f;
    paddingy = 50.f;
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
    rect[1].setPosition(910, 300);
    rect[2].setPosition(50, 550);
    rect[3].setPosition(910, 550);

}
void Game::initText(){
    //Setting the text object and font
    try{
        if (!(font.loadFromFile("arial.ttf"))) throw "Bad Font Load\n";
        text.setFont(font);
        /*for (int i = 0; i < 4 ; ++i)
            textInRect[i].setFont(font);*/
        fontInRect.loadFromFile("arial_bold.TTF");
        for (int i = 0; i<4 ; ++i)
            textInRect[i].setFont(fontInRect);

        std::cout<<"Font loaded successfully"<<std::endl;
    }
    catch(const char* err){
        std::cerr<< "[ERROR]: " << err;
    }
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

    //updating the text
    text.setString("WELCOME TO FOURIELIZER");
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setCharacterSize(50);
    text.setPosition(sf::Vector2f(310.f, 50.f));

    textInRect[0].setString("  Square Wave");
    textInRect[1].setString("Triangular Wave");
    textInRect[2].setString("Saw-tooth Wave");
    textInRect[3].setString("Music Visualizer");

    for (int i = 0 ; i<3 ; ++i){
        textInRect[i].setFillColor(sf::Color::Black);
        textInRect[i].setCharacterSize(40);
        textInRect[i].setPosition(sf::Vector2f(rect[i].getPosition().x + paddingx, rect[i].getPosition().y + paddingy));
    }
        textInRect[3].setFillColor(sf::Color::Black);
        textInRect[3].setCharacterSize(40);
        textInRect[3].setPosition(sf::Vector2f(rect[3].getPosition().x + paddingx, rect[3].getPosition().y + paddingy));



    //tracking the mouse clicks
    if ( sf::Mouse::getPosition(*this->window).x > rect[0].getPosition().x && sf::Mouse::getPosition(*this->window).x < (rect[0].getPosition().x + rectWidth) && sf::Mouse::getPosition(*this->window).y > rect[0].getPosition().y && (sf::Mouse::getPosition(*this->window).y < rect[0].getPosition().y + rectHeight) && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left ){
        std::cout<<"Mouse Clicked on 1st rect\n";
    }
    if ( sf::Mouse::getPosition(*this->window).x > rect[1].getPosition().x && sf::Mouse::getPosition(*this->window).x < (rect[1].getPosition().x + rectWidth) && sf::Mouse::getPosition(*this->window).y > rect[1].getPosition().y && (sf::Mouse::getPosition(*this->window).y < rect[1].getPosition().y + rectHeight) && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left ){
        std::cout<<"Mouse Clicked on 2nd rect\n";
    }
    if ( sf::Mouse::getPosition(*this->window).x > rect[2].getPosition().x && sf::Mouse::getPosition(*this->window).x < (rect[2].getPosition().x + rectWidth) && sf::Mouse::getPosition(*this->window).y > rect[2].getPosition().y && (sf::Mouse::getPosition(*this->window).y < rect[2].getPosition().y + rectHeight) && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left ){
        std::cout<<"Mouse Clicked on 3rd rect\n";
    }
    if ( sf::Mouse::getPosition(*this->window).x > rect[3].getPosition().x && sf::Mouse::getPosition(*this->window).x < (rect[3].getPosition().x + rectWidth) && sf::Mouse::getPosition(*this->window).y > rect[3].getPosition().y && (sf::Mouse::getPosition(*this->window).y < rect[3].getPosition().y + rectHeight) && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left ){
        std::cout<<"Mouse Clicked on 4th rect\n";
    }


    //sf::Mouse::getPosition(*this->window).y//relative to the screen

    //Update mouse position
    //std::cout<<"Mouse Position: "<<sf::Mouse::getPosition().x<<","<<sf::Mouse::getPosition().y<<std::endl; //relative to the screen


}

void Game::render(){ //This is where all the display stuff happens
    this->window->clear();

    //Draw game objects

    for (int i = 0 ; i<4 ; ++i){
        this->window->draw(rect[i]);
        this->window->draw(textInRect[i]);
    }

    this->window->draw(text);


    this->window->display(); //Tell the app that it is done drawing
}

