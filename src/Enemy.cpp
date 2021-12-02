#include "Enemy.h"

Enemy::Enemy(float x, float y): MovableObject(x, y)
{
    //ctor
}

Enemy::~Enemy()
{
    //dtor
}

Enemy::Enemy(const Enemy& other): MovableObject::MovableObject(other)
{
    //copy ctor
}

Enemy& Enemy::operator=(const Enemy& rhs)
{
    if (this != &rhs){
        MovableObject::operator=(rhs);
    }

    return *this;
}

const std::string Enemy::str() const
{
    return "Enemy : " + getPosition().str();
}

Enemy* Enemy::clone() const
{
    return new Enemy(*this);
}
