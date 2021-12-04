#include "MovableObjectView.h"

MovableObjectView::MovableObjectView()
{
    //ctor
}

MovableObjectView::~MovableObjectView()
{
    //dtor
}

MovableObjectView::MovableObjectView(const MovableObjectView& other): sprites(other.sprites)
{
    //Clear the current list then clone all the objects inside the other list
    this->objects.clear();
    for(size_t i=0; i<other.sprites.size(); i++)
    {
        this->objects.push_back(other.objects.at(i)->clone());
    }
}


MovableObjectView& MovableObjectView::operator=(const MovableObjectView& rhs)
{
    if (this == &rhs) return *this;

    //Copy the sprites and the list of objects
    this->sprites = rhs.sprites;

    this->objects.clear();
    for(size_t i=0; i<rhs.sprites.size(); i++)
    {
        this->objects.push_back(rhs.objects.at(i)->clone());
    }

    return *this;
}

std::vector<MovableObject*> MovableObjectView::getObjects() const
{
    //Return a copy of the lists of objects
    std::vector<MovableObject*> result;
    for(size_t i=0; i<this->objects.size(); i++)
    {
        result.push_back(this->objects.at(i)->clone());
    }
    return result;
}

//Getter
std::vector<sf::Sprite> MovableObjectView::getSprites() const
{
    return this->sprites;
}

//Add a copy of an object in the objects list
void MovableObjectView::addObject(MovableObject* object)
{
    this->objects.push_back(object->clone());
}

//Add the texture and the sprite in the sprites list
void MovableObjectView::addSprite(sf::Sprite sprite, sf::Texture* texture)
{
    //Set the texture to the sprite and add the sprite to the list
    sprite.setTexture(*texture);
    this->sprites.push_back(sprite);
}

//Remove the object of its list and remove its sprites in the sprites list
void MovableObjectView::removeObject(MovableObject* object)
{
    for(size_t i=0; i<this->objects.size(); i++)
    {
        if(*object == *(this->objects.at(i)))
        {
            this->objects.erase(this->objects.begin() + i);
            this->sprites.erase(this->sprites.begin() + i);
        }
    }
}

void MovableObjectView::render(sf::RenderWindow* window)
{
    //For each objects get the sprite that matches its index and position it at the position of the matching object and draw it on the window passed in argument
    for(size_t i=0; i<this->objects.size(); i++)
    {
        this->sprites.at(i).setPosition(this->objects.at(i)->getX(), this->objects.at(i)->getY());
        window->draw(this->sprites.at(i));
    }
}

void MovableObjectView::moveObjects(int direction)
{
    //The direction is 0 for the right and 1 for the left
    //Get the changement required by the direction then move all the objects of the list of that value for the x
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
