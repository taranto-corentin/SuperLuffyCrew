#include "Character.h"

//Test
Character::Character(float y): y(y), jumping(false), lifePoint(3)
{
 std::cout << "constructor called" << std::endl;
}

Character::~Character()
{
    //dtor
}

Character::Character(const Character& other): y(other.y), jumping(other.jumping), lifePoint(other.lifePoint)
{
    //copy ctors
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

const int Character::getLifePoint() const
{
    return lifePoint;
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

void Character::takeDamage()
{
    this->lifePoint--;
}

void Character::gainLife()
{
    this->lifePoint++;
}
