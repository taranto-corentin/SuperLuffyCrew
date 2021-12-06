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
        //Window objects
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event events;
        //Textures and sprites
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

        //Game objects
        GroundView groundView;
        PowerView powerView;
        CharacterView characterView;
        LifeView lifeView;
        MeatView meatView;
        EndLevelView endLevelView;
        EnemyView enemyView;

        bool gameRestart = false;

        //Init methods
        void initWindow();
        void initBackground();
        void initVariables();

    public:
        Game();
        virtual ~Game();
        Game(const Game& other);
        Game& operator=(const Game& rhs);

        //Accessors
        const bool running() const;

        //Methods
        void pollEvents();
        void update();
        void render();
        void renderGround();
        void renderBackground();
};

#endif // GAME_H
