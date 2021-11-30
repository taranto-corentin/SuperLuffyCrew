#include "MeatView.h"

MeatView::MeatView()
{
    Meat* meat = new Meat(500, 600 - 128);
    Meat* meat2 = new Meat(845, 600-128);
    this->meats.push_back(meat);
    this->meats.push_back(meat2);

    //Load image
    sf::Image image;
    if(!image.loadFromFile("assets/meat.png"))
    {
        std::cout << "ERROR::MEAT IMAGE NOT FOUND !!!" << std::endl;
    }

    //Load texture
    this->meatTexture.loadFromImage(image);

    //Load the sprites
    for(size_t i=0; i<this->meats.size(); i++)
    {
        sf::Sprite sprite;
        this->meatSprite.push_back(sprite);
        this->meatSprite.at(i).setTexture(this->meatTexture);
        this->meatSprite.at(i).setScale(2.f, 2.f);
    }
}

MeatView::~MeatView()
{
    //dtor
}

MeatView::MeatView(const MeatView& other): meats(other.meats), meatTexture(other.meatTexture), meatSprite(other.meatSprite)
{
    //copy ctor
}

MeatView& MeatView::operator=(const MeatView& rhs)
{
    if (this != &rhs){
        this->meats = rhs.meats;
        this->meatSprite = rhs.meatSprite;
        this->meatTexture = rhs.meatTexture;
    }
    return *this;
}

std::vector<Meat*> MeatView::getMeats() const
{
    return this->meats;
}

void MeatView::render(sf::RenderWindow* window)
{
    for(size_t i=0; i<this->meatSprite.size(); i++)
    {
        this->meatSprite.at(i).setPosition(this->meats.at(i)->getX(), this->meats.at(i)->getY());
        window->draw(this->meatSprite.at(i));
    }
}

void MeatView::moveMeat(int movement)
{
    float change = 0.f;
    switch(movement)
    {
        case 0:
            change = 4.f;
            break;
        case 1:
            change = -4.f;
            break;
    }

    for(size_t i=0; i<this->meats.size(); i++)
    {
        this->meats.at(i)->changePosition(change, 0.f);
    }
}

void MeatView::eatMeat(int index)
{
    std::cout << str() << std::endl;
    meats.erase(meats.begin() + index);
    meatSprite.erase(meatSprite.begin() + index);
}

std::string MeatView::str() const
{
    std::string result;
    for(size_t i=0; i<this->meats.size(); i++)
    {
        result += this->meats.at(i)->str() + "\n";
    }
    return result;
}
