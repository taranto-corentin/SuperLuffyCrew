#ifndef POWER_H
#define POWER_H

#include <iostream>

#include "Position.h"
#include "MovableObject.h"

class Power : public MovableObject
{
    private:


    public:
        Power(float x, float y);
        virtual ~Power();
        Power(const Power& other);
        Power& operator=(const Power& other);

        //Methods
        const std::string str() const;
};

#endif // POWER_H
