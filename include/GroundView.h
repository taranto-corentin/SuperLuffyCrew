#ifndef GROUNDVIEW_H
#define GROUNDVIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <vector>

#include "Obstacle.h"
#include "MovableObjectView.h"


class GroundView : public MovableObjectView
{
    private:


    public:
        GroundView();
        virtual ~GroundView();
        GroundView(const GroundView& other);
        GroundView& operator=(const GroundView& other);
        const std::string str() const;
};

#endif // GROUNDVIEW_H
