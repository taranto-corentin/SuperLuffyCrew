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

    //Load image
    sf::Image groundImage;
    if(!groundImage.loadFromFile("assets/Ground.png"))
    {
        std::cout << "ERROR::GROUND IMAGE NOT FOUND !!!" << std::endl;
    }

    //Load texture
    sf::Texture texture;
    texture.loadFromImage(groundImage);
    //this->addTexture(texture);

    //Load the sprites
    for(size_t i=0; i<this->getObjects().size(); i++)
    {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(2.f, 2.f);
        this->addSprite(sprite);
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
