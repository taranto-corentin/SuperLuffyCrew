#include "MeatView.h"

MeatView::MeatView()
{
    Meat* meat = new Meat(500, 600 - 128);
    Meat* meat2 = new Meat(845, 600-128);
    this->addObject(meat);
    this->addObject(meat2);

    //Load texture
    sf::Texture* texture = new sf::Texture();
    if(!texture->loadFromFile("assets/meat.png"))
    {
        std::cout << "ERROR::MEAT IMAGE NOT FOUND !!!" << std::endl;
    }

    //Load the sprites
    for(size_t i=0; i<this->getObjects().size(); i++)
    {
        sf::Sprite sprite;
        sprite.setScale(2.f, 2.f);
        this->addSprite(sprite, texture);
    }
}

MeatView::~MeatView()
{
    //dtor
}

MeatView::MeatView(const MeatView& other)
{
    //copy ctor
}

MeatView& MeatView::operator=(const MeatView& rhs)
{
    if (this != &rhs){

    }
    return *this;
}

//When the character eats a piece of meat, it's removed from the level
void MeatView::eatMeat(int index)
{
    this->removeObject(this->getObjects().at(index));
}

//To String
const std::string MeatView::str() const
{
    return "Meat view";
}
