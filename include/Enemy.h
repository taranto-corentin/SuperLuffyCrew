#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

#include "Position.h"
#include "MovableObject.h"

class Enemy : public MovableObject
{
    private:


    public:
        Enemy(float x, float y);
        virtual ~Enemy();
        Enemy(const Enemy& other);
        Enemy& operator=(const Enemy& other);

        //Methods
        const std::string str() const;
        Enemy* clone() const;
};

#endif // ENEMY_H
