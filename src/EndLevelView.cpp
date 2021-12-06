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

EndLevelView::EndLevelView(const EndLevelView& other):  endLevels(other.endLevels)
{
    //copy ctor
}

EndLevelView& EndLevelView::operator=(const EndLevelView& rhs)
{
    if (this != &rhs){
        this->endLevels = rhs.endLevels;
    }
    return *this;
}

std::vector<EndLevel*> EndLevelView::getEndLevels()
{
    return this->endLevels;
}

void EndLevelView::setPowerView(PowerView* powerView)
{
    this->powerView = powerView;
}

void EndLevelView::render(sf::RenderWindow* window)
{
    MovableObjectView::render(window);
}

const std::string EndLevelView::str() const
{
    std::string result;
    for(size_t i=0; i<this->endLevels.size(); i++)
    {
        result += this->endLevels.at(i)->str() + "\n";
    }
    return result;
}


