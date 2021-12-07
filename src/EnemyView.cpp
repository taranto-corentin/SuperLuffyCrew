#include "EnemyView.h"

EnemyView::EnemyView()
{
    /*Enemy* enemy1 = new Enemy(1150, 600 - 128);
    this->addObject(enemy1);
    Enemy* enemy2 = new Enemy(1250, 600 - 128);
    this->addObject(enemy2);
    Enemy* enemy3 = new Enemy(1620, 600 - 256);
    this->addObject(enemy3);
    Enemy* enemy4 = new Enemy(1920, 600 - 128);
    this->addObject(enemy4);
    Enemy* enemy5 = new Enemy(2550, 600 - 128);
    this->addObject(enemy5);
    Enemy* enemy6 = new Enemy(3118, 600 - 384);
    this->addObject(enemy6);
    Enemy* enemy7 = new Enemy(3450, 600 - 192);
    this->addObject(enemy7);
    Enemy* enemy8 = new Enemy(3770, 600 - 256);
    this->addObject(enemy8);
    Enemy* enemy9 = new Enemy(4000, 600 - 128);
    this->addObject(enemy9);
    Enemy* enemy10 = new Enemy(4200, 600 - 128);
    this->addObject(enemy10);
    Enemy* enemy11 = new Enemy(4500, 600 - 128);
    this->addObject(enemy11);

    //Load texture
    sf::Texture* texture = new sf::Texture();
    if(!texture->loadFromFile("assets/Dragon_Kaido.png"))
    {
        std::cout << "ERROR::ENEMY IMAGE NOT FOUND !!!" << std::endl;
    }

    //Load the sprites
    for(size_t i=0; i<this->getObjects().size(); i++)
    {
        sf::Sprite sprite;
        sprite.setScale(2.f, 2.f);
        this->addSprite(sprite, texture);
    }*/
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

//Setter
void EnemyView::setPowerView(PowerView* powerView)
{
    this->powerView = powerView;
}

//The character kills the enemy at the 'index' position
void EnemyView::killEnemy(int index)
{
    this->powerView->turnOffLuffy(index);
    this->removeObject(this->getObjects().at(index));
}

//To String
const std::string EnemyView::str() const
{
    return "Enemy view";
}

