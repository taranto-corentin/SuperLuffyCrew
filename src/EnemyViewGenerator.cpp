#include "EnemyViewGenerator.h"

EnemyViewGenerator::EnemyViewGenerator()
{
    //ctor
}

EnemyViewGenerator::~EnemyViewGenerator()
{
    //dtor
}

EnemyViewGenerator::EnemyViewGenerator(const EnemyViewGenerator& other): builder(other.builder)
{
    //copy ctor
}

EnemyViewGenerator& EnemyViewGenerator::operator=(const EnemyViewGenerator& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->builder = rhs.builder;

    return *this;
}

EnemyView EnemyViewGenerator::make()
{
    return this->builder.addEnemy(Enemy(1150, WINDOW_HEIGHT - 128))
                        .addEnemy(Enemy(1250, WINDOW_HEIGHT - 128))
                        .addEnemy(Enemy(1620, WINDOW_HEIGHT - 256))
                        .addEnemy(Enemy(1920, WINDOW_HEIGHT - 128))
                        .addEnemy(Enemy(2550, WINDOW_HEIGHT - 128))
                        .addEnemy(Enemy(3118, WINDOW_HEIGHT - 384))
                        .addEnemy(Enemy(3450, WINDOW_HEIGHT - 192))
                        .addEnemy(Enemy(3770, WINDOW_HEIGHT - 256))
                        .addEnemy(Enemy(4000, WINDOW_HEIGHT - 128))
                        .addEnemy(Enemy(4200, WINDOW_HEIGHT - 128))
                        .addEnemy(Enemy(4500, WINDOW_HEIGHT - 128))
                        .getResult();
}
