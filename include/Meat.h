#ifndef MEAT_H
#define MEAT_H

#include <iostream>

#include "Position.h"

class Meat
{
    private:
        Position position;

    public:
        Meat(float x, float y);
        virtual ~Meat();
        Meat(const Meat& other);
        Meat& operator=(const Meat& other);

        //Methods
        void changePosition(const float x, const float y);
        const float getX() const;
        const float getY() const;
        const std::string str() const;
};

#endif // MEAT_H
