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
        //MeatView(const MeatView& other);
        LifeView& operator=(const LifeView& other);

        //Methods
        void render(sf::RenderWindow* window, int nbLife);
        void updateLifeTxt(int nbLife);
    /*


    //
    private:
        //Game logic
        std::vector<Meat*> meats;
            //GroundView* groundView;
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
        std::string str() const;*/
};

#endif // LIFEVIEW_H
