#include "Enemy.h"

Enemy::Enemy(float x, float y): position(Position(x, y))
{
    //ctor
}

Enemy::~Enemy()
{
    //dtor
}

Enemy::Enemy(const Enemy& other): position(other.position)
{
    //copy ctor
}

Enemy& Enemy::operator=(const Enemy& rhs)
{
    if (this != &rhs){
        this->position = rhs.position;
    }

    return *this;
}

void Enemy::changePosition(const float x, const float y)
{
    this->position.changePosition(x, y);
}

const float Enemy::getX() const
{
    return this->position.getX();
}

const float Enemy::getY() const
{
    return this->position.getY();
}

std::string Enemy::str() const
{
    return "Enemy : " + position.str();
}
