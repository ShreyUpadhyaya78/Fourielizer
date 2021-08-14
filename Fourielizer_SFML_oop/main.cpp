//headers
#include"./include/Game.h"


//declarations


int main()
{
    Game game; //init Game object

    //Setting the text object and font
    sf::Font font;
    try{
        if (!(font.loadFromFile("/resource/arial.ttf"))) throw "Bad Font Load\n";
    }
    catch(const char* err){
        std::cerr<< "[ERROR]: " << err;
    }
    sf::Text text;
    text.setFont(font);

    //Game Loop
    while (game.isWindowOpen())
    {

        game.pollEvents(); //event poll

        //Update
        game.update();
        //Render
        game.render();

        //drawing the game
        game.draw();
        //drawGame::gameDraw();
    }

    return 0;
}
