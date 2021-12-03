#include "PowerView.h"

PowerView::PowerView()
{
    Power* meraMera1 = new Power(150, 600-128);
    this->powers.push_back(meraMera1);
    Power* meraMera2 = new Power(300, 390);
    this->powers.push_back(meraMera2);
    Power* meraMera3 = new Power(420, 600-128);
    this->powers.push_back(meraMera3);

    std::cout << "Powers from the constructor : " << std::endl;
    for(size_t i=0; i<this->powers.size(); i++)
    {
        std::cout << this->powers.at(i)->str() << std::endl;
    }

    //Load image of the Mera Mera fruit
    sf::Image meraMeraImage;
    if(!meraMeraImage.loadFromFile("assets/MeraMera.png"))
    {
        std::cout << "ERROR::MERA MERA FRUIT IMAGE NOT FOUND !!!" << std::endl;
    }

    //Load texture
    this->meraMeraTexture.loadFromImage(meraMeraImage);

    //Load the sprites
    for(size_t i=0; i<this->powers.size(); i++)
    {
        sf::Sprite sprite;
        sprite.setTexture(this->meraMeraTexture);
        sprite.setScale(1.f, 1.f);
        powerSprites.push_back(sprite);
    }
}

PowerView::~PowerView()
{
    for(size_t i=0; i<this->powers.size(); i++)
    {
        delete this->powers.at(i);
    }
    this->powers.clear();
}

PowerView::PowerView(const PowerView& other): powers(other.powers), meraMeraTexture(other.meraMeraTexture), powerSprites(other.powerSprites)
{
    //copy ctor
}

PowerView& PowerView::operator=(const PowerView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->powers = rhs.powers;
    this->meraMeraTexture = rhs.meraMeraTexture;
    this->powerSprites = rhs.powerSprites;

    return *this;
}

std::vector<Power*> PowerView::getPowers() const
{
    return this->powers;
}

bool PowerView::getIsInFire() const
{
    return this->isInFire;
}

void PowerView::turnOffLuffy(int index)
{
    this->isInFire = false;
}

void PowerView::render(sf::RenderWindow* window)
{
    activePowerSprite.setPosition(800-70,80); //800-70,15
    if(this->getIsInFire()) {
        window->draw(activePowerSprite);
    }
    for(size_t i=0; i<this->powerSprites.size(); i++)
    {
        this->powerSprites.at(i).setPosition(this->powers.at(i)->getX(), this->powers.at(i)->getY());
        window->draw(this->powerSprites.at(i));
    }
}

void PowerView::movePowers(int movement)
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

    for(size_t i=0; i<this->powers.size(); i++)
    {
        this->powers.at(i)->changePosition(changement, 0.f);
    }
}

void PowerView::assignPower(int index)
{
    //Assign the power
    std::cout << "MeraMera" << std::endl;
    activePowerSprite = powerSprites.at(index);
    this->isInFire = true;
    std::cout << this->getIsInFire() << std::endl;

    Power* power = powers.at(index);
    powers.erase(powers.begin() + index);
    delete power;
    powerSprites.erase(powerSprites.begin() + index);
}

const std::string PowerView::str() const
{
    std::string result;
    for(size_t i=0; i<this->powers.size(); i++)
    {
        result += this->powers.at(i)->str() + "\n";
    }
    return result;
}
