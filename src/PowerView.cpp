#include "PowerView.h"

PowerView::PowerView()
{
    /*Power* meraMera1 = new Power(150, 600-128);
    this->powers.push_back(meraMera1);
    Power* meraMera2 = new Power(300, 390);
    this->powers.push_back(meraMera2);*/
    Power* meraMera3 = new Power(100, 600-128);
    this->addObject(meraMera3);

    //Load texture
    sf::Texture* texture = new sf::Texture();
    if(!texture->loadFromFile("assets/MeraMera.png"))
    {
        std::cout << "ERROR::MERA MERA IMAGE NOT FOUND !" << std::endl;
    }

    //Load the sprites
    for(size_t i=0; i<this->getObjects().size(); i++)
    {
        sf::Sprite sprite;
        this->addSprite(sprite, texture);
    }
}

PowerView::~PowerView()
{

}

PowerView::PowerView(const PowerView& other): MovableObjectView::MovableObjectView(other)
{
    //copy ctor
}

PowerView& PowerView::operator=(const PowerView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    MovableObjectView::operator=(rhs);

    return *this;
}

bool PowerView::getIsInFire() const
{
    return this->isInFire;
}

void PowerView::turnOffLuffy(int index)
{
    this->isInFire = false;
}

void PowerView::assignPower(int index)
{
    //Assign the power
    activePowerSprite = this->getSprites().at(index);
    this->isInFire = true;

    //Power* power = this->getObjects().at(index);
//    powers.erase(powers.begin() + index);
//    delete power;
//    powerSprites.erase(powerSprites.begin() + index);
    this->removeObject(this->getObjects().at(index));
}

const std::string PowerView::str() const
{
    return "Power view";
}
