#include "Game.h"

Game::Game()
{
    initVariables();
    initWindow();
    initBackground();

    sf::Image winImage;
    sf::Image loseImage;
    sf::Image mainMenuImage;
    sf::Image playImage;
    sf::Image quitImage;
    if(!winImage.loadFromFile("assets/LevelPassed.png"))
    {
        std::cout << "ERROR::EndLevel IMAGE NOT FOUND !!!" << std::endl;
    }

    if(!loseImage.loadFromFile("assets/GameOver.png"))
    {
        std::cout << "ERROR::EndLevel IMAGE NOT FOUND !!!" << std::endl;
    }

    if(!mainMenuImage.loadFromFile("assets/MainMenu.png"))
    {
        std::cout << "ERROR::EndLevel IMAGE NOT FOUND !!!" << std::endl;
    }

    if(!playImage.loadFromFile("assets/Play.png"))
    {
        std::cout << "ERROR::EndLevel IMAGE NOT FOUND !!!" << std::endl;
    }

    if(!quitImage.loadFromFile("assets/Quit.png"))
    {
        std::cout << "ERROR::EndLevel IMAGE NOT FOUND !!!" << std::endl;
    }

    //Set images and textures for each image
    this->winTextures.loadFromImage(winImage);
    this->winSprite.setTexture(this->winTextures);
    this->winSprite.setScale(1.f, 1.f);

    this->loseTextures.loadFromImage(loseImage);
    this->loseSprite.setTexture(this->loseTextures);
    this->loseSprite.setScale(1.f, 1.f);

    this->mainMenuTextures.loadFromImage(mainMenuImage);
    this->mainMenuSprite.setTexture(this->mainMenuTextures);
    this->mainMenuSprite.setScale(1.f, 1.f);

    this->playTextures.loadFromImage(playImage);
    this->playSprite.setTexture(this->playTextures);
    this->playSprite.setScale(0.25f, 0.25f);
    this->playSprite.setPosition(50, 325);

    this->quitTextures.loadFromImage(quitImage);
    this->quitSprite.setTexture(this->quitTextures);
    this->quitSprite.setScale(0.25f, 0.25f);
    this->quitSprite.setPosition(50, 450);
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
    this->window->setFramerateLimit(30);
}

void Game::initVariables()
{
    this->characterView.setGroundView(&groundView);
    //this->enemyView.setGroundView(&groundView);
    this->characterView.setPowerView(&powerView);
    this->characterView.setEnemyView(&enemyView);
    this->characterView.setMeatView(&meatView);
    this->characterView.setEndLevelView(&endLevelView);
    this->enemyView.setPowerView(&powerView);
}

void Game::initBackground()
{
    if(!worldBackgroundTexture.loadFromFile("assets/Background.png"))
    {
        std::cout << "ERROR::WORLD BACKGROUND IMAGE NOT FOUND !!!" << std::endl;
    }
    this->worldBackgroundSprite.setTexture(this->worldBackgroundTexture);
    this->worldBackgroundSprite.setScale(1.f, 1.f);
}
/*
void Game::playMusic(int window)
{
    bool inFire = this->powerView.getIsInFire();
    bool musicDifferent = (musicPlaying != window || (musicPlaying == 1 && inFire != wasInFire));

    if (musicDifferent) {
        // stop previous music
        music.stop();
    } else {
        return;
    }

    bool success;
    bool loop = true;

    switch(window) {
        case 0:
            success = music.openFromFile("assets/gameOver.wav");
            loop = false;
            break;
        case 1: case 2: case 3: case4:
            if ( inFire )
            {
                success = music.openFromFile("assets/power.wav");
            } else {
                success = music.openFromFile("assets/background.wav");
                music.setPlayingOffset(sf::seconds(3));
            }

            break;
        case 5:
            success = music.openFromFile("assets/completedLevel.wav");
            loop = false;
            break;
        case 7:
            success = music.openFromFile("assets/mainMenu.ogg");
            break;
    }

    if (!success) {
        std::cout << "COULDN'T LOAD MUSIC ";
        return;
    }

    music.setVolume(30);
    music.setLoop(loop);
    music.play();

    musicPlaying = window;
    wasInFire = inFire;
}*/

void Game::checkCollisionsAndMove(int move)
{
    int index = this->characterView.checkCollision(move);
    int indexEnemy = this->characterView.checkCollisionWithEnemies(move);
    int indexPower = this->characterView.checkCollisionWithPowers(move);
    int indexMeat = this->characterView.checkCollisionWithMeats(move);
    int indexEndLevel = this->characterView.checkCollisionWithEndLevel(move);
    //Move the obstacles
    if(index == -1 && indexEnemy == -1)
    {
        this->groundView.moveObjects(move);
        this->powerView.moveObjects(move);
        this->enemyView.moveObjects(move);
        this->meatView.moveObjects(move);
        this->endLevelView.moveEndLevel(move);
    }
    //Update the image of the character
    this->characterView.moveCharacter(move);
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
        if(characterView.getAdvancementState() == 7){

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    sf::Vector2i MousePos = sf::Mouse::getPosition(*(this->window)) ;
                    sf::FloatRect objPos = playSprite.getGlobalBounds() ;
                if(objPos.contains(MousePos.x, MousePos.y)){
                    this->characterView.setAdvancementState(1);
                }
                sf::FloatRect objPos2 = quitSprite.getGlobalBounds() ;
                if(objPos2.contains(MousePos.x, MousePos.y)){
                    this->window->close();
                }
            }

        }else {
            if(characterView.getAdvancementState() == 1)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    checkCollisionsAndMove(1);
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    checkCollisionsAndMove(0);
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
/*
                    if ( !this->characterView.getCharacter().isJumping() )
                    {
                        if ( !buffer.loadFromFile("assets/jump.wav") )
                        {
                            return;
                        }
                        sound = sf::Sound(buffer);
                        sound.play();
                    }
                    */

                    this->characterView.jump();
                }
            }
            //Display level passed
            else {
                if(characterView.getAdvancementState() == 5){
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                    {
                        this->characterView.setAdvancementState(1);
                    }
                } else {
                    if(characterView.getAdvancementState() == 0){
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                        {
                            this->characterView.setAdvancementState(7);
                        }
                    }
                }
            }
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

void Game::renderBackground()
{
    this->window->draw(this->worldBackgroundSprite);
}

void Game::render()
{
    if(characterView.getAdvancementState() == 7){
        this->window->clear();
        window->draw(this->mainMenuSprite);
        window->draw(this->playSprite);
        window->draw(this->quitSprite);

        //playMusic(7);
    }else {
        if(characterView.getAdvancementState() == 1)
        {
            //playMusic(1);
            //Clear the content of the window
            this->window->clear();
            //Draw the world background
            this->renderBackground();
            //Draw the game objects
            this->groundView.render(this->window);
            this->characterView.render(this->window);
            this->lifeView.render(this->window, characterView.getCharacter().getLifePoint());
            this->lifeView.updateLifeTxt(characterView.getCharacter().getLifePoint());
            this->powerView.render(this->window);
            this->enemyView.render(this->window);
            this->meatView.render(this->window);
            this->endLevelView.render(this->window);
            //std::cout << "hero life before: " << characterView.getCharacter().getLifePoint() << std::endl;
        } else{
            if(characterView.getAdvancementState() == 5){
                //playMusic(5);
                this->window->clear();
                this->characterView = CharacterView();
                this->groundView = GroundView();
                this->enemyView = EnemyView();
                this->powerView = PowerView();
                this->meatView = MeatView();
                this->endLevelView = EndLevelView();
                initVariables();
                window->draw(this->winSprite);
            } else {
                if(characterView.getAdvancementState() == 0){
                    //playMusic(0);
                    this->window->clear();
                    this->characterView = CharacterView();
                    this->groundView = GroundView();
                    this->enemyView = EnemyView();
                    this->powerView = PowerView();
                    this->meatView = MeatView();
                    this->endLevelView = EndLevelView();
                    initVariables();
                    std::cout << "state 0" << std::endl;
                    window->draw(this->loseSprite);
                }
            }

        }
    }
    //Display the new content of the window
    this->window->display();
}
