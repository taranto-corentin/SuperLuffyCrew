#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

class Character
{
    private:
        float y;
        bool jumping;

    public:
        Character(float y=0);
        virtual ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);

        //Accessors
        const float getY() const;
        void setJumping(const bool jumping);
        const bool isJumping() const;

        //Methods for the game
        void jump(const float change);
};

#endif // CHARACTER_H
