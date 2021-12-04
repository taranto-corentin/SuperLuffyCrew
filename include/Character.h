#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

class Character
{
    private:
        float y;
        bool jumping;
        int lifePoint;
        bool invincible;
    public:
        Character(float y=0);
        virtual ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);

        //Accessors
        const float getY() const;
        const int getLifePoint() const;
        void setJumping(const bool jumping);
        const bool isJumping() const;
        void setInvincible(const bool invincible);
        const bool isInvincible() const;
        //Methods for the game
        void jump(const float change);
        void takeDamage();
        void gainLife();
};

#endif // CHARACTER_H
