#include "PowerView.h"

PowerView::PowerView()
{
    Power* gomuGomu = new Power(150, 600-128);
    this->powers.push_back(gomuGomu);
    Power* baraBara = new Power(300, 390);
    this->powers.push_back(baraBara);
    Power* meraMera = new Power(420, 600-128);
    this->powers.push_back(meraMera);

    std::cout << "Powers from the constructor : " << std::endl;
    for(size_t i=0; i<this->powers.size(); i++)
    {
        std::cout << this->powers.at(i)->str() << std::endl;
    }

    //Load image of the Gomu Gomu fruit
    sf::Image gomuGomuImage;
    if(!gomuGomuImage.loadFromFile("assets/GomuGomu.png"))
    {
        std::cout << "ERROR::GOMU GOMU FRUIT IMAGE NOT FOUND !!!" << std::endl;
    }
    //Load image of the Bara Bara fruit
    sf::Image baraBaraImage;
    if(!baraBaraImage.loadFromFile("assets/BaraBara.jpg"))
    {
        std::cout << "ERROR::BARA BARA FRUIT IMAGE NOT FOUND !!!" << std::endl;
    }
    //Load image of the Mera Mera fruit
    sf::Image meraMeraImage;
    if(!meraMeraImage.loadFromFile("assets/MeraMera.jpg"))
    {
        std::cout << "ERROR::MERA MERA FRUIT IMAGE NOT FOUND !!!" << std::endl;
    }

    //Load texture
    this->gomuGomuTexture.loadFromImage(gomuGomuImage);
    this->baraBaraTexture.loadFromImage(baraBaraImage);
    this->meraMeraTexture.loadFromImage(meraMeraImage);

    //Load the sprites
    sf::Sprite sprite1;
    sprite1.setTexture(this->gomuGomuTexture);
    powerSprites.push_back(sprite1);

    sf::Sprite sprite2;
    sprite2.setTexture(this->baraBaraTexture);
    powerSprites.push_back(sprite2);

    sf::Sprite sprite3;
    sprite3.setTexture(this->meraMeraTexture);
    powerSprites.push_back(sprite3);

    for(size_t i=0; i<this->powers.size(); i++)
    {
        this->powerSprites.at(i).setScale(2.f, 2.f);
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

PowerView::PowerView(const PowerView& other): powers(other.powers), gomuGomuTexture(other.gomuGomuTexture), baraBaraTexture(other.baraBaraTexture), meraMeraTexture(other.meraMeraTexture), powerSprites(other.powerSprites)
{
    //copy ctor
}

PowerView& PowerView::operator=(const PowerView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->powers = rhs.powers;
    this->gomuGomuTexture = rhs.gomuGomuTexture;
    this->baraBaraTexture = rhs.baraBaraTexture;
    this->meraMeraTexture = rhs.meraMeraTexture;
    this->powerSprites = rhs.powerSprites;

    return *this;
}

std::vector<Power*> PowerView::getPowers() const
{
    return this->powers;
}

void PowerView::render(sf::RenderWindow* window)
{
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
