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
    }

    return 0;
}
