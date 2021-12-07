#include "Game.h"

Game::Game()
{
    initVariables();
    initWindow();
    initBackground();

    //Load the images for the menus
    sf::Image winImage;
    sf::Image loseImage;
    sf::Image mainMenuImage;
    sf::Image playImage;
    sf::Image quitImage;
    if(!winImage.loadFromFile("assets/GameFinished.png"))
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

}


Game::Game(const Game& other)
{
    //Copy of the window objects
    this->window = other.window;
    this->videoMode = other.videoMode;
    this->events = other.events;

    //Copy of the textures and sprites
    this->winTextures = other.winTextures;
    this->winSprite = other.winSprite;
    this->loseTextures = other.loseTextures;
    this->loseSprite = other.loseSprite;
    this->mainMenuTextures = other.mainMenuTextures;
    this->mainMenuSprite = other.mainMenuSprite;
    this->playTextures = other.playTextures;
    this->playSprite = other.playSprite;
    this->quitTextures = other.quitTextures;
    this->quitSprite = other.quitSprite;
    this->worldBackgroundTexture = other.worldBackgroundTexture;
    this->worldBackgroundSprite = other.worldBackgroundSprite;

    //Copy of the game objects
    this->groundView = other.groundView;
    this->characterView = other.characterView;
    this->powerView = other.powerView;
    this->lifeView = other.lifeView;
    this->meatView = other.meatView;
    this->endLevelView = other.endLevelView;
    this->enemyView = other.enemyView;

    this->gameRestart = other.gameRestart;
}

Game& Game::operator=(const Game& rhs)
{

    if (this == &rhs) return *this; // handle self assignment

    //Copy of the window objects
    this->window = rhs.window;
    this->videoMode = rhs.videoMode;
    this->events = rhs.events;

    //Copy of the textures and sprites
    this->winTextures = rhs.winTextures;
    this->winSprite = rhs.winSprite;
    this->loseTextures = rhs.loseTextures;
    this->loseSprite = rhs.loseSprite;
    this->mainMenuTextures = rhs.mainMenuTextures;
    this->mainMenuSprite = rhs.mainMenuSprite;
    this->playTextures = rhs.playTextures;
    this->playSprite = rhs.playSprite;
    this->quitTextures = rhs.quitTextures;
    this->quitSprite = rhs.quitSprite;
    this->worldBackgroundTexture = rhs.worldBackgroundTexture;
    this->worldBackgroundSprite = rhs.worldBackgroundSprite;

    //Copy of the game objects
    this->groundView = rhs.groundView;
    this->characterView = rhs.characterView;
    this->powerView = rhs.powerView;
    this->lifeView = rhs.lifeView;
    this->meatView = rhs.meatView;
    this->endLevelView = rhs.endLevelView;
    this->enemyView = rhs.enemyView;

    this->gameRestart = rhs.gameRestart;

    return *this;
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
    this->enemyView = EnemyViewGenerator().make();

    //Set all the views where it is necessary
    this->characterView.setGroundView(&groundView);
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
//SOUND
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
        case 1: case 2: case 3: case 4:
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
}

void Game::checkCollisionsAndMove(int move)
{
    //Check the collisions
    int index = this->characterView.checkCollision(move);
    int indexEnemy = this->characterView.checkCollisionWithEnemies(move);
    this->characterView.checkCollisionWithPowers(move);
    this->characterView.checkCollisionWithMeats(move);
    this->characterView.checkCollisionWithEndLevel(move);
    //Move the obstacles
    if(index == -1 && indexEnemy == -1)
    {
        this->groundView.moveObjects(move);
        this->powerView.moveObjects(move);
        this->enemyView.moveObjects(move);
        this->meatView.moveObjects(move);
        this->endLevelView.moveObjects(move);
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
            //If we click on the cross at the right top corner of the window it closes the window
            case sf::Event::Closed:
                this->window->close();
                break;
        }
        if(characterView.getAdvancementState() == 7){
            //Restart the game if the user press space and close the window if the user press esc
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                this->characterView.setAdvancementState(1);
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                this->window->close();
            }
            //Allows to use a sprite as a button by checking if the user clicked on the sprite or not
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
                //Move the character accordingly to the keys pressed and check the collision with any potential elements
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    checkCollisionsAndMove(1);
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    checkCollisionsAndMove(0);
                }
                //Make the character jump
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    if ( !this->characterView.getCharacter().isJumping() )
                    {
                        if ( !buffer.loadFromFile("assets/jump.wav") )
                        {
                            return;
                        }
                        sound = sf::Sound(buffer);
                        sound.play();
                    }

                    this->characterView.jump();
                }
            }
            //Display level passed
            else {
                if(characterView.getAdvancementState() == 5){
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                    {
                        this->characterView.setAdvancementState(7);
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
    //Display the elements of the main menu
    if(characterView.getAdvancementState() == 7){
        this->window->clear();
        window->draw(this->mainMenuSprite);
        window->draw(this->playSprite);
        window->draw(this->quitSprite);

        playMusic(7);
    }
    else if(characterView.getAdvancementState() == 1)
    {
        playMusic(1);

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
    }
    else if(characterView.getAdvancementState() == 5){
        playMusic(5);

        this->window->clear();
        this->resetGame();
        window->draw(this->winSprite);
    }
    else if(characterView.getAdvancementState() == 0){
        playMusic(0);

        this->window->clear();
        this->resetGame();
        window->draw(this->loseSprite);
    }

    //Display the new content of the window
    this->window->display();
}

void Game::resetGame()
{
    //Reinitialize the variables to their basic state
    this->characterView = CharacterView();
    this->groundView = GroundView();
    this->powerView = PowerView();
    this->meatView = MeatView();
    this->endLevelView = EndLevelView();
    initVariables();
}
