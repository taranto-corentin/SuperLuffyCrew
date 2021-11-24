#include "CharacterView.h"

CharacterView::CharacterView()
{
    //Init the character
    this->character = Character(this->startingY);

    //Init the jump done
    this->jumpDone = false;

    //Load images
    sf::Image characterImages[2][3];
    if(!characterImages[1][0].loadFromFile("assets/LuffyRight1.png") ||
       !characterImages[1][1].loadFromFile("assets/LuffyRight2.png") ||
       !characterImages[1][2].loadFromFile("assets/LuffyRight3.png") ||
       !characterImages[0][0].loadFromFile("assets/LuffyLeft1.png") ||
       !characterImages[0][1].loadFromFile("assets/LuffyLeft2.png") ||
       !characterImages[0][2].loadFromFile("assets/LuffyLeft3.png"))
    {
        std::cout << "ERROR::CHARACTER IMAGES NOT FOUND !!!" << std::endl;
    }

    //Loading the textures
    for(int i=0; i<this->nbTypeMovement; i++)
    {
        for(int j=0; j<this->nbImagesPerMovement; j++)
        {
            this->characterTextures[i][j].loadFromImage(characterImages[i][j]);
        }
    }

    //Initialization of the sprite
    this->characterSprite.setTexture(characterTextures[1][0]);

    //Defining the position of the sprite
    this->characterSprite.setPosition(this->xPos, this->character.getY());
}

CharacterView::~CharacterView()
{
    //dtor
}

CharacterView::CharacterView(const CharacterView& other)
{

}

CharacterView& CharacterView::operator=(const CharacterView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->character = rhs.character;
    this->jumpDone = rhs.jumpDone;
    this->groundView = rhs.groundView;
    //Copy the textures
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            this->characterTextures[i][j] = rhs.characterTextures[i][j];
        }
    }

    this->characterSprite = rhs.characterSprite;

    return *this;
}

void CharacterView::setGroundView(GroundView* groundView)
{
    this->groundView = groundView;
}

void CharacterView::setPowerView(PowerView* powerView)
{
    this->powerView = powerView;
}

void CharacterView::render(sf::RenderWindow* window)
{
    window->draw(this->characterSprite);
}

void CharacterView::moveCharacter(const int movement)
{
    //Movement 0=left and 1=right
    if(!this->character.isJumping())
    {
        //Check if there is nothing under the character
        std::vector<Obstacle*> grounds = this->groundView->getObstacles();
        bool hasToFall = true;
        for(size_t i=0; i<grounds.size(); i++)
        {
            if(((this->xPos <= grounds.at(i)->getX() + 64 && this->xPos >= grounds.at(i)->getX()) ||
               (this->xPos - this->characterWidth <= grounds.at(i)->getX() && this->xPos + this->characterWidth >= grounds.at(i)->getX())) &&
               this->character.getY() + 64 == grounds.at(i)->getY())
            {
                hasToFall = false;
            }
        }
        if(hasToFall)
        {
            this->character.setJumping(true);
            this->jumpDone = true;
            return;
        }

        //Change the posture of the character
        const sf::Texture* texture = characterSprite.getTexture();
        if(texture == &(this->characterTextures[movement][0]))
        {
            this->characterSprite.setTexture(this->characterTextures[movement][1]);
        }
        else if(texture == &(this->characterTextures[movement][1]))
        {
            this->characterSprite.setTexture(this->characterTextures[movement][2]);
        }
        else
        {
            this->characterSprite.setTexture(this->characterTextures[movement][0]);
        }
    }
}

void CharacterView::jump()
{
    //Setting the attribute jumping to true if it is not the case already
    if(!this->character.isJumping())
    {
        this->character.setJumping(true);
    }
    //Checking if the character should go up or down
    if(this->character.getY() <= this->jumpHeight)
    {
        this->jumpDone = true;
    }
    if(!this->jumpDone)
    {
        int index = this->checkCollision();
        if(index != -1)
        {
            this->jumpDone = true;
            this->character.jump(7);
            return;
        }
        this->character.jump(-6);
        this->characterSprite.setPosition(this->xPos, this->character.getY());
    }
    else
    {
        int index = this->checkCollision();
        if(index != -1)
        {
            //Recover the obstacles
            std::vector<Obstacle*> grounds = this->groundView->getObstacles();
            //Put it at the right height
            this->character.jump(grounds.at(index)->getY() - this->character.getY() - 64);
            //Stop the jump
            this->jumpDone = false;
            this->character.setJumping(false);
            //Put the sprite at the new positions
            this->characterSprite.setPosition(this->xPos, this->character.getY());

            return;
        }
        this->character.jump(7);
        this->characterSprite.setPosition(this->xPos, this->character.getY());
    }
}

const bool CharacterView::isJumping() const
{
    return this->character.isJumping();
}

const int CharacterView::checkCollision(int movement) const
{
    std::vector<Obstacle*> grounds = this->groundView->getObstacles();
    for(size_t i=0; i<grounds.size(); i++)
    {
        int newX = grounds.at(i)->getX();
        int newY = grounds.at(i)->getY();
        switch(movement)
        {
            case 0:
                newX += 4.f;
                break;
            case 1:
                newX -= 4.f;
                break;
        }
        if(this->xPos + this->characterWidth <= newX || this->xPos >= newX + this->characterWidth)
        {
            continue;
        }
        if(this->character.getY() + 64 <= newY || newY + 64 <= this->character.getY())
        {
            continue;
        }
        return i;
    }
    return -1;
}

const int CharacterView::checkCollisionWithPowers(int movement) const
{
    std::vector<Power*> powers = this->powerView->getPowers();

    for(size_t i=0; i<powers.size(); i++)
    {
        int newX = powers.at(i)->getX();
        int newY = powers.at(i)->getY();
        switch(movement)
        {
            case 0:
                newX += 4.f;
                break;
            case 1:
                newX -= 4.f;
                break;
        }
        if(this->xPos + this->characterWidth <= newX || this->xPos >= newX + this->characterWidth)
        {
            continue;
        }
        if(this->character.getY() + 64 <= newY || newY + 64 <= this->character.getY())
        {
            continue;
        }
        std::cout << "Collision with power !" << std::endl;
        return i;
    }
    return -1;
}

const int CharacterView::checkCollisionWithEnemies(int movement) const
{
    std::vector<Enemy*> enemies = this->enemyView->getEnemys();

    for(size_t i=0; i<enemies.size(); i++)
    {
        int newX = enemies.at(i)->getX();
        int newY = enemies.at(i)->getY();
        switch(movement)
        {
            case 0:
                newX += 4.f;
                break;
            case 1:
                newX -= 4.f;
                break;
        }
        if(this->xPos + this->characterWidth <= newX || this->xPos >= newX + this->characterWidth)
        {
            continue;
        }

        if(this->character.getY() + 64 <= newY || newY + 64 <= this->character.getY())
        {
            if(i == enemies.size() - 1)
            {
                std::cout << "No collision in the Y" << std::endl;
            }

            continue;
        }
        std::cout << "Collision !!!" << std::endl;
        return i;
    }
    return -1;
}
