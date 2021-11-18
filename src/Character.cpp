#include "Character.h"

Character::Character(float y): y(y), jumping(false)
{

}

Character::~Character()
{
    //dtor
}

Character::Character(const Character& other): y(other.y), jumping(other.jumping)
{
    //copy ctor
}

Character& Character::operator=(const Character& rhs)
{
    if(this == &rhs)
    {
        return *this;
    }

    this->y = rhs.y;
    this->jumping = rhs.jumping;

    return *this;
}

const float Character::getY() const
{
    return y;
}

void Character::setJumping(const bool jumping)
{
    this->jumping = jumping;
}

const bool Character::isJumping() const
{
    return jumping;
}

void Character::jump(const float change)
{
    this->y += change;
}
