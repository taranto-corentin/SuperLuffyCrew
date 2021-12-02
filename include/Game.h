#ifndef GAME_H
#define GAME_H

#include "CharacterView.h"
#include "GroundView.h"

#include "PowerView.h"
#include "EnemyView.h"
#include "LifeView.h"

class Game
{
    private:
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event events;
        sf::Texture winTextures;
        sf::Sprite winSprite;

        //Ground images
        GroundView groundView;
        PowerView powerView;
        CharacterView characterView;
        LifeView lifeView;

        MeatView meatView;
        EndLevelView endLevelView;
        EnemyView enemyView;

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
