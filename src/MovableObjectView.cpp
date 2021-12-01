#include "MovableObjectView.h"

MovableObjectView::MovableObjectView()
{
    //ctor
}

MovableObjectView::~MovableObjectView()
{
    //dtor
}

MovableObjectView::MovableObjectView(const MovableObjectView& other)
{

}


MovableObjectView& MovableObjectView::operator=(const MovableObjectView& rhs)
{
    if (this == &rhs) return *this;

    return *this;
}

std::vector<MovableObject*> MovableObjectView::getObjects() const
{
    std::vector<MovableObject*> result;
    for(size_t i=0; i<this->objects.size(); i++)
    {
        result.push_back(this->objects.at(i)->clone());
    }
    return result;
}

std::vector<sf::Texture> MovableObjectView::getTextures() const
{
    return this->textures;
}

std::vector<sf::Sprite> MovableObjectView::getSprites() const
{
    return this->sprites;
}

void MovableObjectView::addObject(MovableObject* object)
{
    this->objects.push_back(object->clone());
}

void MovableObjectView::addTexture(sf::Texture texture)
{
    this->textures.push_back(texture);
}

void MovableObjectView::addSprite(sf::Sprite sprite)
{
    this->sprites.push_back(sprite);
}

void MovableObjectView::render(sf::RenderWindow* window)
{
    for(size_t i=0; i<this->objects.size(); i++)
    {
        this->sprites.at(i).setPosition(this->objects.at(i)->getX(), this->objects.at(i)->getY());
        window->draw(this->sprites.at(i));
    }
}

void MovableObjectView::moveObjects(int direction)
{
    float changement;
    switch(direction)
    {
        case 0:
            changement = 4.f;
            break;
        case 1:
            changement = -4.f;
            break;
    }
    for(size_t i=0; i<this->objects.size(); i++)
    {
        this->objects.at(i)->changePosition(changement, 0.f);
    }
}
