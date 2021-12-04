#include "Power.h"

Power::Power(float x, float y): MovableObject(x, y)
{
    //ctor
}

Power::~Power()
{
    //dtor
}

Power::Power(const Power& other): MovableObject::MovableObject(other)
{
    //copy ctor
}

Power& Power::operator=(const Power& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    MovableObject::operator=(rhs);

    return *this;
}

//To String
const std::string Power::str() const
{
    return "Power ; " + this->getPosition().str();
}

//Return a copy of a power
Power* Power::clone() const
{
    return new Power(*this);
}
