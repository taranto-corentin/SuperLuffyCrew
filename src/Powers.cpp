#include "Powers.h"

Powers::Powers(float x, float y): position(Position(x, y))
{
    //ctor
}

Powers::~Powers()
{
    //dtor
}

Powers::Powers(const Powers& other): position(other.position)
{
    //copy ctor
}

Powers& Powers::operator=(const Powers& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->position = rhs.position;

    return *this;
}

void Obstacle::changePosition(const float x, const float y)
{
    this->position.changePosition(x, y);
}

const float Obstacle::getX() const
{
    return this->position.getX();
}

const float Obstacle::getY() const
{
    return this->position.getY();
}
