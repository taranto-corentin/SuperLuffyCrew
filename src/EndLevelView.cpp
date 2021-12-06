#include "EndLevelView.h"

EndLevelView::EndLevelView()
{
    EndLevel* endLevel = new EndLevel(4800, 600 - 190);
    this->addObject(endLevel);

    //Load texture
    sf::Texture* texture = new sf::Texture();
    if(!texture->loadFromFile("assets/GoingMerry.png"))
    {
        std::cout << "ERROR::GOING MERRY IMAGE NOT FOUND !" << std::endl;
    }

    //Load the sprites
    for(size_t i=0; i<this->getObjects().size(); i++)
    {
        sf::Sprite sprite;
        sprite.setScale(2.f, 2.f);
        this->addSprite(sprite, texture);
    }
}

EndLevelView::~EndLevelView()
{
    //dtor
}

EndLevelView::EndLevelView(const EndLevelView& other): MovableObjectView::MovableObjectView(other)
{
    //copy ctor
}

EndLevelView& EndLevelView::operator=(const EndLevelView& rhs)
{
    if (this != &rhs){
        MovableObjectView::operator=(rhs);
    }
    return *this;
}

const std::string EndLevelView::str() const
{
    return "End level";
}
