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

void MovableObjectView::render(sf::RenderWindow* window)
{
    for(size_t i=0; i<this->objects.size(); i++)
    {
        this->sprites.at(i).setPosition(this->objects.at(i)->getX(), this->objects.at(i)->getY());
        window->draw(this->sprites.at(i));
    }
}
