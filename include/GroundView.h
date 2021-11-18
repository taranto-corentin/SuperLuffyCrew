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


class GroundView
{
    private:
        //Game logic
        std::vector<Obstacle*> obstacles;

        //Images
        sf::Texture groundTexture;
        std::vector<sf::Sprite> groundSprites;

    public:
        GroundView();
        virtual ~GroundView();
        GroundView(const GroundView& other);
        GroundView& operator=(const GroundView& other);

        //Accessors
        std::vector<Obstacle*> getObstacles();

        //Methods
        void render(sf::RenderWindow* window);
        void moveGround(int movement);
};

#endif // GROUNDVIEW_H
