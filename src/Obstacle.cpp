#include "Obstacle.h"

Obstacle::Obstacle(float x, float y): position(Position(x, y))
{

}

Obstacle::~Obstacle()
{

}

Obstacle::Obstacle(const Obstacle& other): position(other.position)
{

}

Obstacle& Obstacle::operator=(const Obstacle& rhs)
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
