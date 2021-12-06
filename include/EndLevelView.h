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
        //Game logic
        std::vector<EndLevel*> endLevels;
        GroundView* groundView;
        PowerView* powerView;
    public:
        EndLevelView();
        virtual ~EndLevelView();
        EndLevelView(const EndLevelView& other);
        EndLevelView& operator=(const EndLevelView& other);

        //Accessors
        std::vector<EndLevel*> getEndLevels();

        //Methods
        void render(sf::RenderWindow* window);
        void setPowerView(PowerView* powerView);
        const std::string str() const;

    protected:
};

#endif // ENDLEVELVIEW_H
