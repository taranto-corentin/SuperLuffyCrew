#include "PowerView.h"

PowerView::PowerView()
{
    Power* meraMera1 = new Power(785, 600-128);
    this->addObject(meraMera1);
    Power* meraMera2 = new Power(2900, 600-128);
    this->addObject(meraMera2);
    Power* meraMera3 = new Power(3642, 600-384);
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

PowerView::PowerView(const PowerView& other): MovableObjectView::MovableObjectView(other), isInFire(other.isInFire), activePowerTexture(other.activePowerTexture), activePowerSprite(other.activePowerSprite)
{
    //copy ctor
}

PowerView& PowerView::operator=(const PowerView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    MovableObjectView::operator=(rhs);
    this->isInFire = rhs.isInFire;
    this->activePowerTexture = rhs.activePowerTexture;
    this->activePowerSprite = rhs.activePowerSprite;

    return *this;
}

//When the character eats a power, he's in fire
bool PowerView::getIsInFire() const
{
    return this->isInFire;
}

//When the effect of the power disapears, the character is not in fire anymore
void PowerView::turnOffLuffy(int index)
{
    this->isInFire = false;
}

void PowerView::render(sf::RenderWindow* window)
{
    MovableObjectView::render(window);
    if(this->isInFire)
    {
        window->draw(activePowerSprite);
    }
}

//Assign the power to the character
void PowerView::assignPower(int index)
{
    //Show the active power in the right-top corner of the window
    activePowerSprite = this->getSprites().at(index);
    activePowerSprite.setPosition(800-70,80);

    this->isInFire = true;

    this->removeObject(this->getObjects().at(index));
}

//To String
const std::string PowerView::str() const
{
    return "Power view";
}
