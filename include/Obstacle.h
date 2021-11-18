#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>

#include "Position.h"

class Obstacle
{
    private:
        Position position;

    public:
        Obstacle(float x, float y);
        virtual ~Obstacle();
        Obstacle(const Obstacle& other);
        Obstacle& operator=(const Obstacle& other);

        //Methods
        void changePosition(const float x, const float y);
        const float getX() const;
        const float getY() const;
};

#endif // OBSTACLE_H
