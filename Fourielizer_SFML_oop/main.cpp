//headers
#include"./include/Game.h"


//declarations


int main()
{
    Game game; //init Game object

    //Game Loop
    while (game.isWindowOpen())
    {

        game.pollEvents(); //event poll

        //Update
        game.update();

        //Render
        game.render();

        //drawGame::gameDraw();
    }

    return 0;
}
