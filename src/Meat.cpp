#include "Meat.h"

Meat::Meat(float x, float y): MovableObject(x, y)
{
    //ctor
}

Meat::~Meat()
{
    //dtor
}

Meat::Meat(const Meat& other): MovableObject::MovableObject(other)
{
    //copy ctor
}

Meat& Meat::operator=(const Meat& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    MovableObject::operator=(rhs);

    return *this;
}

//To String
const std::string Meat::str() const
{
    return "Meat ; " + this->getPosition().str();
}

//Return a copy of a meat
Meat* Meat::clone() const
{
    return new Meat(*this);
}
