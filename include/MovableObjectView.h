#ifndef MOVABLEOBJECTVIEW_H
#define MOVABLEOBJECTVIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <vector>

#include "MovableObject.h"

class MovableObjectView
{
    private:
        std::vector<MovableObject*> objects;
        std::vector<sf::Texture> textures;
        std::vector<sf::Sprite> sprites;

    public:
        MovableObjectView();
        virtual ~MovableObjectView();
        MovableObjectView(const MovableObjectView& other);
        MovableObjectView& operator=(const MovableObjectView& rhs);

        //Accessors
        std::vector<MovableObject*> getObjects() const;
        std::vector<sf::Texture> getTextures() const;
        std::vector<sf::Sprite> getSprites() const;
        void addObject(MovableObject* object);
        void addTexture(sf::Texture texture);
        void addSprite(sf::Sprite sprite);

        //Methods
        void render(sf::RenderWindow* window);
        void moveObjects(int direction);
        virtual const std::string str() const = 0;
};

#endif // MOVABLEOBJECTVIEW_H
