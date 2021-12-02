#ifndef ENEMYVIEW_H
#define ENEMYVIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <vector>
#include <chrono>
#include "Enemy.h"
#include "GroundView.h"
#include "PowerView.h"

class EnemyView
{
    private:

        //Game logic
        std::vector<Enemy*> enemys;
        GroundView* groundView;
        PowerView* powerView;
        //Images
        sf::Texture enemyTexture;
        std::vector<sf::Sprite> enemySprite;
    public:
        EnemyView();
        virtual ~EnemyView();
        EnemyView(const EnemyView& other);
        EnemyView& operator=(const EnemyView& other);

        //Accessors
        std::vector<Enemy*> getEnemys();

        //Methods
        void render(sf::RenderWindow* window);
        void setPowerView(PowerView* powerView);
        void moveEnemy(int movement);
        void killEnemy(int index);
        std::string str() const;

    protected:
};

#endif // ENEMYVIEW_H
