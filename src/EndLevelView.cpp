#include "EndLevelView.h"

EndLevelView::EndLevelView()
{
    EndLevel* endLevel = new EndLevel(4600, 600 - 190);
    this->endLevels.push_back(endLevel);

    //Load image
    sf::Image endLevelImage;
    if(!endLevelImage.loadFromFile("assets/GoingMerry.png"))
    {
        std::cout << "ERROR::EndLevel IMAGE NOT FOUND !!!" << std::endl;
    }

    //Load texture
    this->endLevelTexture.loadFromImage(endLevelImage);

    //Load the sprites
    for(size_t i=0; i<this->endLevels.size(); i++)
    {
        sf::Sprite sprite;
        this->endLevelSprite.push_back(sprite);
        this->endLevelSprite.at(i).setTexture(this->endLevelTexture);
        this->endLevelSprite.at(i).setScale(2.f, 2.f);
    }
}

EndLevelView::~EndLevelView()
{
    //dtor
}

EndLevelView::EndLevelView(const EndLevelView& other):  endLevels(other.endLevels), endLevelTexture(other.endLevelTexture), endLevelSprite(other.endLevelSprite)
{
    //copy ctor
}

EndLevelView& EndLevelView::operator=(const EndLevelView& rhs)
{
    if (this != &rhs){
        this->endLevels = rhs.endLevels;
        this->endLevelSprite = rhs.endLevelSprite;
        this->endLevelTexture = rhs.endLevelTexture;
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
    for(size_t i=0; i<this->endLevelSprite.size(); i++)
    {
        this->endLevelSprite.at(i).setPosition(this->endLevels.at(i)->getX(), this->endLevels.at(i)->getY());
        window->draw(this->endLevelSprite.at(i));
    }
}

void EndLevelView::moveEndLevel(int movement)
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

    for(size_t i=0; i<this->endLevels.size(); i++)
    {
        this->endLevels.at(i)->changePosition(changement, 0.f);
    }
}

std::string EndLevelView::str() const
{
    std::string result;
    for(size_t i=0; i<this->endLevels.size(); i++)
    {
        result += this->endLevels.at(i)->str() + "\n";
    }
    return result;
}


