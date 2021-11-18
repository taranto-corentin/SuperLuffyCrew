#include "Position.h"

Position::Position(float x, float y): x(x), y(y)
{
    //ctor
}

Position::~Position()
{
    //dtor
}

Position::Position(const Position& other): x(other.x), y(other.y)
{
    //copy ctor
}

Position& Position::operator=(const Position& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->x = rhs.x;
    this->y = rhs.y;

    return *this;
}

void Position::changePosition(const float x, const float y)
{
    this->x += x;
    this->y += y;
}

const float Position::getX() const
{
    return this->x;
}

const float Position::getY() const
{
    return this->y;
}
