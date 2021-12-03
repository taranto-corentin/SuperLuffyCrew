#ifndef MEATVIEW_H
#define MEATVIEW_H


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <vector>

#include "Meat.h"
#include "MovableObjectView.h"

class MeatView : public MovableObjectView
{
    private:


    public:
        MeatView();
        virtual ~MeatView();
        MeatView(const MeatView& other);
        MeatView& operator=(const MeatView& other);

        //Methods
        void eatMeat(int index);
        const std::string str() const;
};

#endif // MEATVIEW_H
