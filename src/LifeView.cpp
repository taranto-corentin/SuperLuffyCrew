#include "LifeView.h"

#include <sstream>

LifeView::LifeView()
{
    //Load image
    sf::Image image;
    if(!image.loadFromFile("assets/life.png"))
    {
        std::cout << "ERROR::LIFE IMAGE NOT FOUND !!!" << std::endl;
    }

    //Load texture
    this->lifeTexture.loadFromImage(image);

    //Load the sprite
    this->lifeSprite.setTexture(this->lifeTexture);
    this->lifeSprite.setScale(2.f, 2.f);
}

LifeView::~LifeView()
{
    //dtor
}

LifeView& LifeView::operator=(const LifeView& rhs)
{
    if (this != &rhs){
        this->lifeSprite = rhs.lifeSprite;
        this->lifeTexture = rhs.lifeTexture;
    }
    return *this;
}

void LifeView::render(sf::RenderWindow* window, int nbLife)
{
    lifeSprite.setPosition(800-70,15);
    window->draw(lifeSprite);

    sf::Font font;
    if (!font.loadFromFile("assets/retro.ttf")) {
        std::cout << "couldn't load font";
    }
    lifeText.setCharacterSize(45);
    lifeText.setFont(font);
    lifeText.setFillColor(sf::Color::Red);

    int nLife = nbLife;
    if (nLife < 0) {
        nLife = 0;
    }
    lifeText.setString( std::to_string(nLife) );

    lifeText.setPosition(800-100, 20);
    window->draw(lifeText);
}

void LifeView::updateLifeTxt(int nbLife)
{
    int nLife = nbLife;
    if (nLife < 0) {
        nLife = 0;
    }
    lifeText.setString( std::to_string(nLife) );
}
