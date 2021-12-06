#ifndef LIFEVIEW_H
#define LIFEVIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>


class LifeView
{
    private:
        sf::Text lifeText;
        sf::Texture lifeTexture;
        sf::Sprite lifeSprite;
    public:
        LifeView();
        virtual ~LifeView();
        LifeView(const LifeView& other);
        LifeView& operator=(const LifeView& other);

        //Methods
        void render(sf::RenderWindow* window, int nbLife);
        void updateLifeTxt(int nbLife);
};

#endif // LIFEVIEW_H
