#include "EndLevel.h"

EndLevel::EndLevel(float x, float y): MovableObject(x, y)
{
    //ctor
}

EndLevel::~EndLevel()
{
    //dtor
}

EndLevel::EndLevel(const EndLevel& other):MovableObject::MovableObject(other)
{
    //copy ctor
}

EndLevel& EndLevel::operator=(const EndLevel& rhs)
{
    if (this == &rhs){
        MovableObject::operator=(rhs);
    }
    return *this;
}

const std::string EndLevel::str() const
{
    return "EndLevel : " + getPosition().str();
}

EndLevel* EndLevel::clone() const
{
    return new EndLevel(*this);
}
