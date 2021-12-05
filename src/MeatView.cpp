#include "MeatView.h"

MeatView::MeatView()
{
      Meat* meat1 = new Meat(2290, 600 - 384);
      this->addObject(meat1);
      Meat* meat2 = new Meat(3180, 600 - 256);
      this->addObject(meat2);
      Meat* meat3 = new Meat(3642, 600 - 256);
      this->addObject(meat3);

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
