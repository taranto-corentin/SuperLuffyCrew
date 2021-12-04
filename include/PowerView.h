#ifndef POWERVIEW_H
#define POWERVIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <vector>

#include "Power.h"
#include "MovableObjectView.h"

class PowerView : public MovableObjectView
{
    private:
        //Game logic
        bool isInFire = false;

        sf::Texture activePowerTexture;
        sf::Sprite activePowerSprite;

    public:
        PowerView();
        virtual ~PowerView();
        PowerView(const PowerView& other);
        PowerView& operator=(const PowerView& other);

        //Accessors
        bool getIsInFire() const;

        //Methods
        void assignPower(int index);
        const std::string str() const;
        void turnOffLuffy(int index);
};

#endif // POWERVIEW_H
