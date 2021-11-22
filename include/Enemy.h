#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

#include "Position.h"
class Enemy
{
    private:
        Position position;
    public:
        Enemy(float x, float y);
        virtual ~Enemy();
        Enemy(const Enemy& other);
        Enemy& operator=(const Enemy& other);

        //Methods
        void changePosition(const float x, const float y);
        const float getX() const;
        const float getY() const;

    protected:
};

#endif // ENEMY_H
