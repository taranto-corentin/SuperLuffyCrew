#include "Power.h"

Power::Power(float x, float y): position(Position(x, y))
{
    //ctor
}

Power::~Power()
{
    //dtor
}

Power::Power(const Power& other): position(other.position)
{
    //copy ctor
}

Power& Power::operator=(const Power& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->position = rhs.position;

    return *this;
}

void Power::changePosition(const float x, const float y)
{
    this->position.changePosition(x, y);
}

const float Power::getX() const
{
    return this->position.getX();
}

const float Power::getY() const
{
    return this->position.getY();
}
