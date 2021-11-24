#include "EnemyView.h"

EnemyView::EnemyView()
{
    Enemy* enemy = new Enemy(550, 600 - 192);
    this->enemys.push_back(enemy);

    //Load image
    sf::Image enemyImage;
    if(!enemyImage.loadFromFile("assets/Katakuri.png"))
    {
        std::cout << "ERROR::ENEMY IMAGE NOT FOUND !!!" << std::endl;
    }

    //Load texture
    this->enemyTexture.loadFromImage(enemyImage);

    //Load the sprites
    for(size_t i=0; i<this->enemys.size(); i++)
    {
        sf::Sprite sprite;
        this->enemySprite.push_back(sprite);
        this->enemySprite.at(i).setTexture(this->enemyTexture);
        this->enemySprite.at(i).setScale(2.f, 2.f);
    }
}

EnemyView::~EnemyView()
{
    //dtor
}

EnemyView::EnemyView(const EnemyView& other):  enemys(other.enemys), enemyTexture(other.enemyTexture), enemySprite(other.enemySprite)
{
    //copy ctor
}

EnemyView& EnemyView::operator=(const EnemyView& rhs)
{
    if (this != &rhs){
        this->enemys = rhs.enemys;
        this->enemySprite = rhs.enemySprite;
        this->enemyTexture = rhs.enemyTexture;
    }
    return *this;
}

std::vector<Enemy*> EnemyView::getEnemys()
{
    return this->enemys;
}

void EnemyView::render(sf::RenderWindow* window)
{
    for(size_t i=0; i<this->enemySprite.size(); i++)
    {
        this->enemySprite.at(i).setPosition(this->enemys.at(i)->getX(), this->enemys.at(i)->getY());
        window->draw(this->enemySprite.at(i));
    }
}

void EnemyView::moveEnemy(int movement)
{
    float changement = 0.f;
    switch(movement)
    {
        case 0:
            changement = 4.f;
            break;
        case 1:
            changement = -4.f;
            break;
    }

    for(size_t i=0; i<this->enemys.size(); i++)
    {
        this->enemys.at(i)->changePosition(changement, 0.f);
    }
}

