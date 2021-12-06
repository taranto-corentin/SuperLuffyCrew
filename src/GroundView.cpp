#include "GroundView.h"

GroundView::GroundView()
{
    //Creation of the ground logic
    for(int i=0; i<100; i++)
    {
        Obstacle* obstacle = new Obstacle(i * 64, 600 - 64);
        this->addObject(obstacle);
    }
    for(int i=0; i<20; i++)
    {
        Obstacle* obstacleMur = new Obstacle(0, 600 - 64 * i);
        this->addObject(obstacleMur);
        Obstacle* obstacleMur1 = new Obstacle(-64, 600 - 64 * i);
        this->addObject(obstacleMur1);
        Obstacle* obstacleMur2 = new Obstacle(-128, 600 - 64 * i);
        this->addObject(obstacleMur2);
        Obstacle* obstacleMur3 = new Obstacle(-192, 600 - 64 * i);
        this->addObject(obstacleMur3);
        Obstacle* obstacleMur4 = new Obstacle(-256, 600 - 64 * i);
        this->addObject(obstacleMur4);
        Obstacle* obstacleMur5 = new Obstacle(-320, 600 - 64 * i);
        this->addObject(obstacleMur5);
    }

    Obstacle* obstacle = new Obstacle(625, 600-128);
    this->addObject(obstacle);
    Obstacle* obstacle2 = new Obstacle(685, 600-128);
    this->addObject(obstacle2);
    Obstacle* obstacle3 = new Obstacle(685, 600-192);
    this->addObject(obstacle3);

    Obstacle* obstacle4 = new Obstacle(890, 600-128);
    this->addObject(obstacle4);
    Obstacle* obstacle5 = new Obstacle(890, 600-192);
    this->addObject(obstacle5);
    Obstacle* obstacle6= new Obstacle(950, 600-128);
    this->addObject(obstacle6);

    Obstacle* obstacle7 = new Obstacle(1500, 600-192);
    this->addObject(obstacle7);
    Obstacle* obstacle8 = new Obstacle(1560, 600-192);
    this->addObject(obstacle8);
    Obstacle* obstacle9 = new Obstacle(1620, 600-192);
    this->addObject(obstacle9);

    Obstacle* obstacle10 = new Obstacle(2200, 600-192);
    this->addObject(obstacle10);
    Obstacle* obstacle11 = new Obstacle(2260, 600-192);
    this->addObject(obstacle11);
    Obstacle* obstacle12 = new Obstacle(2320, 600-192);
    this->addObject(obstacle12);
    Obstacle* obstacle13 = new Obstacle(2380, 600-192);
    this->addObject(obstacle13);

    Obstacle* obstacle14 = new Obstacle(2260, 600-320);
    this->addObject(obstacle14);
    Obstacle* obstacle15 = new Obstacle(2320, 600-320);
    this->addObject(obstacle15);

    Obstacle* obstacle16 = new Obstacle(2800, 600-192);
    this->addObject(obstacle16);
    Obstacle* obstacle17 = new Obstacle(2864, 600-192);
    this->addObject(obstacle17);
    Obstacle* obstacle18= new Obstacle(2926, 600-192);
    this->addObject(obstacle18);
    Obstacle* obstacle19 = new Obstacle(2990, 600-192);
    this->addObject(obstacle19);
    Obstacle* obstacle20 = new Obstacle(3054, 600-192);
    this->addObject(obstacle20);
    Obstacle* obstacle21= new Obstacle(3118, 600-192);
    this->addObject(obstacle21);
    Obstacle* obstacle22 = new Obstacle(3182, 600-192);
    this->addObject(obstacle22);
    Obstacle* obstacle23 = new Obstacle(3246, 600-192);
    this->addObject(obstacle23);
    Obstacle* obstacle24 = new Obstacle(3246, 600-256);
    this->addObject(obstacle24);
    Obstacle* obstacle25 = new Obstacle(3246, 600-320);
    this->addObject(obstacle25);
    Obstacle* obstacle26 = new Obstacle(3246, 600-192);
    this->addObject(obstacle26);
    Obstacle* obstacle27 = new Obstacle(3182, 600-320);
    this->addObject(obstacle27);
    Obstacle* obstacle28 = new Obstacle(3118, 600-320);
    this->addObject(obstacle28);
    Obstacle* obstacle29 = new Obstacle(3054, 600-320);
    this->addObject(obstacle29);
    //Obstacle* obstacle30 = new Obstacle(2800, 600-128);
    //this->addObject(obstacle30);

    Obstacle* obstacle31 = new Obstacle(3450, 600-128);
    this->addObject(obstacle31);
    Obstacle* obstacle32 = new Obstacle(3578, 600-256);
    this->addObject(obstacle32);
    Obstacle* obstacle33 = new Obstacle(3578, 600-192);
    this->addObject(obstacle33);
    Obstacle* obstacle34 = new Obstacle(3706, 600-320);
    this->addObject(obstacle34);
    Obstacle* obstacle35 = new Obstacle(3706, 600-192);
    this->addObject(obstacle35);
    Obstacle* obstacle36 = new Obstacle(3706, 600-256);
    this->addObject(obstacle36);
    Obstacle* obstacle37 = new Obstacle(3770, 600-192);
    this->addObject(obstacle37);
    Obstacle* obstacle38 = new Obstacle(3834, 600-192);
    this->addObject(obstacle38);
    Obstacle* obstacle39 = new Obstacle(3578, 600-320);
    this->addObject(obstacle39);
    Obstacle* obstacle40 = new Obstacle(3642, 600-320);
    this->addObject(obstacle40);

    Obstacle* obstacle41 = new Obstacle(4300, 600-128);
    this->addObject(obstacle41);
    Obstacle* obstacle42 = new Obstacle(4364, 600-128);
    this->addObject(obstacle42);
    Obstacle* obstacle43 = new Obstacle(4364, 600-192);
    this->addObject(obstacle43);

    for(int i=0; i<20; i++)
    {
        Obstacle* obstacleMur = new Obstacle(5000, 600 - 64 * i);
        this->addObject(obstacleMur);
    }

    //Creation of the texture from the file that contains the image and display a error message in the console if the image is not found
    sf::Texture* texture = new sf::Texture();
    if(!texture->loadFromFile("assets/Ground2.png"))
    {
        std::cout << "ERROR::GROUND IMAGE NOT FOUND !!!" << std::endl;
    }

    //For each objects create a new sprite double the size of the image to have a 64x64 sprite and then add the sprite with the texture
    for(size_t i=0; i<this->getObjects().size(); i++)
    {
        sf::Sprite sprite;
        sprite.setScale(2.f, 2.f);
        this->addSprite(sprite, texture);
    }
}

GroundView::~GroundView()
{

}

GroundView::GroundView(const GroundView& other): MovableObjectView::MovableObjectView(other)
{
    //copy ctor
}

GroundView& GroundView::operator=(const GroundView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    MovableObjectView::operator=(rhs);

    return *this;
}

//To String
const std::string GroundView::str() const
{
    return "Ground view";
}
