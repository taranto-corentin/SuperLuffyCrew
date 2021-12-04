#include "Obstacle.h"

Obstacle::Obstacle(float x, float y): MovableObject(x, y)
{

}

Obstacle::~Obstacle()
{

}

Obstacle::Obstacle(const Obstacle& other): MovableObject::MovableObject(other)
{

}

Obstacle& Obstacle::operator=(const Obstacle& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    MovableObject::operator=(rhs);

    return *this;
}

//To String
const std::string Obstacle::str() const
{
    return "Obstacle : " + this->getPosition().str();
}

//Return a copy of an obstacle
Obstacle* Obstacle::clone() const
{
    return new Obstacle(*this);
}
