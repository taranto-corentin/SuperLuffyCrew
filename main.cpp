#include "Game.h"

int main()
{
    Game game;

    while(game.running())
    {
        //Update the game
        game.update();
        //Render the game
        game.render();
//        if(game.getGameRestart())
//        {
//            std::cout << "restart" << std::endl;
//        }
    }

    return 0;
}
