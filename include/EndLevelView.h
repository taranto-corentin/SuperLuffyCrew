#ifndef ENDLEVELVIEW_H
#define ENDLEVELVIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <vector>
#include <chrono>
#include "Enemy.h"
#include "GroundView.h"
#include "PowerView.h"
#include "EndLevel.h"
#include "MovableObjectView.h"


class EndLevelView : public MovableObjectView
{
    private:


    public:
        EndLevelView();
        virtual ~EndLevelView();
        EndLevelView(const EndLevelView& other);
        EndLevelView& operator=(const EndLevelView& other);

        //Methods
        const std::string str() const;
};

#endif // ENDLEVELVIEW_H
