#include "EnemyView.h"

EnemyView::EnemyView()
{
    Enemy* enemy = new Enemy(550, 600 - 128);
    Enemy* enemy2 = new Enemy(745,600 - 128);
    this->addObject(enemy);
    this->addObject(enemy2);

    //Load texture
    sf::Texture* texture = new sf::Texture();
    if(!texture->loadFromFile("assets/Katakuri.png"))
    {
        std::cout << "ERROR::ENEMY IMAGE NOT FOUND !!!" << std::endl;
    }

    //Load the sprites
    for(size_t i=0; i<this->getObjects().size(); i++)
    {
        sf::Sprite sprite;
        sprite.setScale(2.f, 2.f);
        this->addSprite(sprite, texture);
    }
}

EnemyView::~EnemyView()
{
    //dtor
}

EnemyView::EnemyView(const EnemyView& other): MovableObjectView::MovableObjectView(other)
{
    //copy ctor
}

EnemyView& EnemyView::operator=(const EnemyView& rhs)
{
    if (this != &rhs){
        MovableObjectView::operator=(rhs);
    }
    return *this;
}

void EnemyView::setPowerView(PowerView* powerView)
{
    this->powerView = powerView;
}

void EnemyView::killEnemy(int index)
{
    this->powerView->turnOffLuffy();
    this->removeObject(this->getObjects().at(index));
}

const std::string EnemyView::str() const
{
    return "Enemy view";
}

