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
#include "MovableObjectView.h"

class EnemyView : public MovableObjectView
{
    private:
        //Game logic
        PowerView* powerView;

    public:
        EnemyView();
        virtual ~EnemyView();
        EnemyView(const EnemyView& other);
        EnemyView& operator=(const EnemyView& other);

        //Methods
        void setPowerView(PowerView* powerView);
        void killEnemy(int index);
        const std::string str() const;
};

#endif // ENEMYVIEW_H
