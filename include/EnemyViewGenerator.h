#ifndef ENEMYVIEWGENERATOR_H
#define ENEMYVIEWGENERATOR_H

#include "EnemyViewBuilder.h"

class EnemyViewGenerator
{
    private:
        EnemyViewBuilder builder;

        //Constants
        int WINDOW_HEIGHT = 600;

    public:
        EnemyViewGenerator();
        virtual ~EnemyViewGenerator();
        EnemyViewGenerator(const EnemyViewGenerator& other);
        EnemyViewGenerator& operator=(const EnemyViewGenerator& other);

        //Method for the deisn pattern
        EnemyView make();
};

#endif // ENEMYVIEWGENERATOR_H
