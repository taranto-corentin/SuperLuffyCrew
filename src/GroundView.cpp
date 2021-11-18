#include "GroundView.h"

GroundView::GroundView()
{
    //Creation of the ground logic
    for(int i=0; i<100; i++)
    {
        Obstacle* obstacle = new Obstacle(i * 64, 600 - 64);
        this->obstacles.push_back(obstacle);
    }
    Obstacle* obstacle = new Obstacle(64, 600-128);
    this->obstacles.push_back(obstacle);

    //Load image
    sf::Image groundImage;
    if(!groundImage.loadFromFile("assets/Ground.png"))
    {
        std::cout << "ERROR::GROUND IMAGE NOT FOUND !!!" << std::endl;
    }

    //Load texture
    this->groundTexture.loadFromImage(groundImage);

    //Load the sprites
    for(size_t i=0; i<this->obstacles.size(); i++)
    {
        sf::Sprite sprite;
        this->groundSprites.push_back(sprite);
        this->groundSprites.at(i).setTexture(this->groundTexture);
        this->groundSprites.at(i).setScale(2.f, 2.f);
    }
}

GroundView::~GroundView()
{

}

GroundView::GroundView(const GroundView& other): obstacles(other.obstacles), groundTexture(other.groundTexture), groundSprites(other.groundSprites)
{
    //copy ctor
}

GroundView& GroundView::operator=(const GroundView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->obstacles = rhs.obstacles;
    this->groundTexture = rhs.groundTexture;
    this->groundSprites = rhs.groundSprites;

    return *this;
}

std::vector<Obstacle*> GroundView::getObstacles()
{
    return this->obstacles;
}

void GroundView::render(sf::RenderWindow* window)
{
    for(size_t i=0; i<this->groundSprites.size(); i++)
    {
        this->groundSprites.at(i).setPosition(this->obstacles.at(i)->getX(), this->obstacles.at(i)->getY());
        window->draw(this->groundSprites.at(i));
    }
}

void GroundView::moveGround(int movement)
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

    for(size_t i=0; i<this->obstacles.size(); i++)
    {
        this->obstacles.at(i)->changePosition(changement, 0.f);
    }
}
