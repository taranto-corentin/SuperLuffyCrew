#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include "Position.h"

class MovableObject
{
    private:
        Position position;

    public:
        MovableObject(float x=0.f, float y=0.f);
        virtual ~MovableObject();
        MovableObject(const MovableObject& other);
        MovableObject& operator=(const MovableObject& other);

        //Accessors
        const float getX() const;
        const float getY() const;
        const Position getPosition() const;

        //Operators
        bool operator==(const MovableObject& other);

        //Methods
        void changePosition(const float x, const float y);
        virtual const std::string str() const = 0;
        virtual MovableObject* clone() const = 0;
};

#endif // MOVABLEOBJECT_H
