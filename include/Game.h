#ifndef GAME_H
#define GAME_H

#include "CharacterView.h"
#include "GroundView.h"

#include "PowerView.h"
#include "EnemyView.h"
#include "LifeView.h"
#include "EndLevelView.h"

class Game
{
    private:
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event events;
        sf::Texture winTextures;
        sf::Sprite winSprite;
        sf::Texture loseTextures;
        sf::Sprite loseSprite;
        sf::Texture mainMenuTextures;
        sf::Sprite mainMenuSprite;
        sf::Texture playTextures;
        sf::Sprite playSprite;
        sf::Texture quitTextures;
        sf::Sprite quitSprite;
        //World background
        sf::Texture worldBackgroundTexture;
        sf::Sprite worldBackgroundSprite;

        //Ground images
        GroundView groundView;
        PowerView powerView;
        CharacterView characterView;
        LifeView lifeView;

        MeatView meatView;
        EndLevelView endLevelView;
        EnemyView enemyView;

        bool gameRestart = false;

        //Game logic

        //Init methods
        void initWindow();
        void initBackground();
        void initVariables();
        void initGroundSprite();
        void initGrounds();

    public:
        Game();
        virtual ~Game();

        //Accessors
        const bool running() const;
        const bool getGameRestart() const;
        void setGameRestart(bool gameRestart);

        //Functions
        void pollEvents();
        void update();
        void render();
        void renderGround();
        void renderBackground();
};

#endif // GAME_H
