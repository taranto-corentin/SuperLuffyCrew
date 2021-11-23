#ifndef POWER_H
#define POWER_H

#include <iostream>

#include "Position.h"

class Power
{
    private:
        Position position;

    public:
        Power(float x, float y);
        virtual ~Power();
        Power(const Power& other);
        Power& operator=(const Power& other);

        //Methods
        void changePosition(const float x, const float y);
        const float getX() const;
        const float getY() const;
};

#endif // POWER_H
