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

class MeatView
{
    private:
        //Game logic
        std::vector<Meat*> meats;

        //Images
        sf::Texture meatTexture;
        std::vector<sf::Sprite> meatSprite;
    public:
        MeatView();
        virtual ~MeatView();
        MeatView(const MeatView& other);
        MeatView& operator=(const MeatView& other);

        //Accessors
        std::vector<Meat*> getMeats() const;
        //Methods
        void render(sf::RenderWindow* window);
        void moveMeat(int movement);
        void eatMeat(int index);
        std::string str() const;
};

#endif // MEATVIEW_H
