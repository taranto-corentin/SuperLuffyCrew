#include "EnemyViewBuilder.h"

EnemyViewBuilder::EnemyViewBuilder()
{
    //ctor
}

EnemyViewBuilder::~EnemyViewBuilder()
{
    //dtor
}

EnemyViewBuilder::EnemyViewBuilder(const EnemyViewBuilder& other): enemyView(other.enemyView)
{
    //copy ctor
}

EnemyViewBuilder& EnemyViewBuilder::operator=(const EnemyViewBuilder& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->enemyView = rhs.enemyView;

    return *this;
}

EnemyViewBuilder EnemyViewBuilder::addEnemy(Enemy enemy)
{
    //Add the enemy to the list of the enemy view
    this->enemyView.addObject(&enemy);
    //Create the sprite matching the enemy
    sf::Sprite sprite;
    sprite.setScale(2.f, 2.f);
    //Create the texture for the sprite
    sf::Texture* texture = new sf::Texture();
    if(!texture->loadFromFile("assets/Dragon_Kaido.png"))
    {
        std::cout << "ERROR::ENEMY IMAGE NOT FOUND !!!" << std::endl;
    }
    //Add the sprite to the list of the enemy view
    this->enemyView.addSprite(sprite, texture);

    return *this;
}

EnemyView EnemyViewBuilder::getResult() const
{
    return this->enemyView;
}
