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

class PowerView
{
    private:
        //Game logic
        std::vector<Power*> powers;

        sf::Texture gomuGomuTexture;
        sf::Texture baraBaraTexture;
        sf::Texture meraMeraTexture;
        std::vector<sf::Sprite> powerSprites;

    public:
        PowerView();
        virtual ~PowerView();
        PowerView(const PowerView& other);
        PowerView& operator=(const PowerView& other);

        //Accessors
        std::vector<Power*> getPowers() const;

        //Methods
        void render(sf::RenderWindow* window);
        void movePowers(int movement);
};

#endif // POWERVIEW_H
