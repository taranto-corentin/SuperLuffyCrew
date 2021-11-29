#include "Meat.h"

Meat::Meat(float x, float y): position(Position(x, y))
{
    //ctor
}

Meat::~Meat()
{
    //dtor
}

Meat::Meat(const Meat& other): position(other.position)
{
    //copy ctor
}

Meat& Meat::operator=(const Meat& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->position = rhs.position;

    return *this;
}

void Meat::changePosition(const float x, const float y)
{
    this->position.changePosition(x, y);
}

const float Meat::getX() const
{
    return this->position.getX();
}

const float Meat::getY() const
{
    return this->position.getY();
}

const std::string Meat::str() const
{
    return "Meat ; " + this->position.str();
}
