#ifndef ENEMYVIEWBUILDER_H
#define ENEMYVIEWBUILDER_H

#include "EnemyView.h"

class EnemyViewBuilder
{
    private:
        EnemyView enemyView;

    public:
        EnemyViewBuilder();
        virtual ~EnemyViewBuilder();
        EnemyViewBuilder(const EnemyViewBuilder& other);
        EnemyViewBuilder& operator=(const EnemyViewBuilder& other);

        //Methods for the design pattern
        EnemyViewBuilder addEnemy(Enemy enemy);
        EnemyView getResult() const;
};

#endif // ENEMYVIEWBUILDER_H
