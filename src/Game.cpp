#include "Game.h"

Game::Game()
{
    initVariables();
    initWindow();
}

Game::~Game()
{
    delete window;
}

void Game::initWindow()
{
    //Definition of the size of the window
    this->videoMode.width = 800;
    this->videoMode.height = 600;
    //Creation of the window
    this->window = new sf::RenderWindow(this->videoMode, "Super Luffy Crew", sf::Style::Titlebar | sf::Style::Close);
    //Definition of the FPS of the game
    this->window->setFramerateLimit(20);
}

void Game::initVariables()
{
    this->characterView.setGroundView(&groundView);
    this->enemyView.setGroundView(&groundView);
}

//Accesssors
const bool Game::running() const
{
    return this->window->isOpen();
}

void Game::pollEvents()
{
    //Event polling
    while(this->window->pollEvent(this->events))
    {
        switch(this->events.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            int index = this->characterView.checkCollision(1);
            int indexEnemy = this->characterView.checkCollisionWithEnemies(1);
            //Move the obstacles
            if(index == -1)
            {
                this->groundView.moveGround(1);
                this->powerView.movePowers(1);
                this->enemyView.moveEnemy(1);
            }

            //Move the enemies
            if(indexEnemy == -1)
            {
                this->groundView.moveGround(1);
                this->powerView.movePowers(1);
                this->enemyView.moveEnemy(1);
            }

            //Update the image of the character
            this->characterView.moveCharacter(1);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            int index = this->characterView.checkCollision(0);
            //int indexEnemy = this->characterView.checkCollisionWithEnemies(0);
            if(index == -1)
            {
                //Move the obstacles
                this->groundView.moveGround(0);
                this->powerView.movePowers(0);
                this->enemyView.moveEnemy(0);
            }

            /*if(indexEnemy == -1)
            {
                //Move the obstacles
                this->groundView.moveGround(0);
                this->powerView.movePowers(0);
                this->enemyView.moveEnemy(0);
            }*/


            //Update the image of the character
            this->characterView.moveCharacter(0);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            this->characterView.jump();
        }
    }
    if(this->characterView.isJumping())
    {
        this->characterView.jump();
    }
}

void Game::update()
{
    this->pollEvents();
}

void Game::render()
{
    //Clear the content of the window
    this->window->clear();
    //Draw the game objects
    this->groundView.render(this->window);
    this->characterView.render(this->window);
    this->powerView.render(this->window);
    this->enemyView.render(this->window);
    //Display the new content of the window
    this->window->display();
}
