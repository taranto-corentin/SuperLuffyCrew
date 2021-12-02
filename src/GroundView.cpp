#include "GroundView.h"

GroundView::GroundView()
{
    //Creation of the ground logic
    for(int i=0; i<100; i++)
    {
        Obstacle* obstacle = new Obstacle(i * 64, 600 - 64);
        this->addObject(obstacle);
    }
    Obstacle* obstacle = new Obstacle(64, 600-128);
    this->addObject(obstacle);
    Obstacle* obstacle2 = new Obstacle(300, 390);
    this->addObject(obstacle2);

    //Creation of the texture from the file that contains the image and display a error message in the console if the image is not found
    sf::Texture* texture = new sf::Texture();
    if(!texture->loadFromFile("assets/Ground.png"))
    {
        std::cout << "ERROR::GROUND IMAGE NOT FOUND !!!" << std::endl;
    }

    //For each objects create a new sprite double the size of the image to have a 64x64 sprite and then add the sprite with the texture
    for(size_t i=0; i<this->getObjects().size(); i++)
    {
        sf::Sprite sprite;
        sprite.setScale(2.f, 2.f);
        this->addSprite(sprite, texture);
    }
}

GroundView::~GroundView()
{

}

GroundView::GroundView(const GroundView& other): MovableObjectView::MovableObjectView(other)
{
    //copy ctor
}

GroundView& GroundView::operator=(const GroundView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    MovableObjectView::operator=(rhs);

    return *this;
}

const std::string GroundView::str() const
{
    return "Ground view";
}
