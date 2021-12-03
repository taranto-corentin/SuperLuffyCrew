#ifndef ENDLEVEL_H
#define ENDLEVEL_H

#include <iostream>

#include "Position.h"
#include "MovableObject.h"
class EndLevel: public MovableObject
{
    public:
        EndLevel(float x, float y);
        virtual ~EndLevel();
        EndLevel(const EndLevel& other);
        EndLevel& operator=(const EndLevel& other);

        //Methods
        const std::string str() const;
        EndLevel* clone() const;
    protected:

    private:
};

#endif // ENDLEVEL_H
