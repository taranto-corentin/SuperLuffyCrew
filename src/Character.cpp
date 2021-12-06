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
    this->lifePoint = rhs.lifePoint;

    return *this;
}

//Getters
const float Character::getY() const
{
    return y;
}

const int Character::getLifePoint() const
{
    return lifePoint;
}

const bool Character::isJumping() const
{
    return jumping;
}

//Setters
void Character::setJumping(const bool jumping)
{
    this->jumping = jumping;
}

void Character::setLifePoint(const int lifePoint)
{
    this->lifePoint = lifePoint;
}

//Increase the 'y' position of the character for the jump
void Character::jump(const float change)
{
    this->y += change;
}

//The character lost a life
void Character::takeDamage()
{
    this->lifePoint--;
}

//the character gain a life
void Character::gainLife()
{
    this->lifePoint++;
}

