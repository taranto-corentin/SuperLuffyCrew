#ifndef GAME_H
#define GAME_H

#include "CharacterView.h"
#include "GroundView.h"
#include "PowerView.h"

class Game
{
    private:
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event events;

        //Ground images
        GroundView groundView;
        CharacterView characterView;
        PowerView powerView;

        //Game logic

        //Init methods
        void initWindow();
        void initVariables();
        void initGroundSprite();
        void initGrounds();

    public:
        Game();
        virtual ~Game();

        //Accessors
        const bool running() const;

        //Functions
        void pollEvents();
        void update();
        void render();
        void renderGround();
};

#endif // GAME_H
