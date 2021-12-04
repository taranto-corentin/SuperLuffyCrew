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

//To String
const std::string EndLevel::str() const
{
    return "EndLevel : " + getPosition().str();
}

//Return a copy of the end of the level
EndLevel* EndLevel::clone() const
{
    return new EndLevel(*this);
}
