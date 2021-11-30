#include "MovableObject.h"

MovableObject::MovableObject(float x, float y): position(Position(x, y))
{
    //ctor
}

MovableObject::~MovableObject()
{
    //dtor
}

MovableObject::MovableObject(const MovableObject& other): position(other.position)
{
    //copy ctor
}

MovableObject& MovableObject::operator=(const MovableObject& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->position = rhs.position;

    return *this;
}

void MovableObject::changePosition(const float x, const float y)
{
    this->position.changePosition(x, y);
}

const float MovableObject::getX() const
{
    return this->position.getX();
}

const float MovableObject::getY() const
{
    return this->position.getY();
}

const Position MovableObject::getPosition() const
{
    return this->position;
}
