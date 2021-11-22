#ifndef GAME_H
#define GAME_H

#include "CharacterView.h"
#include "GroundView.h"
<<<<<<< HEAD
#include "PowerView.h"
=======
#include "EnemyView.h"
>>>>>>> refs/remotes/origin/main

class Game
{
    private:
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event events;

        //Ground images
        GroundView groundView;
        CharacterView characterView;
<<<<<<< HEAD
        PowerView powerView;
=======
        EnemyView enemyView;
>>>>>>> refs/remotes/origin/main

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
