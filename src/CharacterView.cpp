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

bool CharacterView::isWin() const
{
    return win;
}

void CharacterView::setWin(bool win)
{
    this->win = win;
}

void CharacterView::setGroundView(GroundView* groundView)
{
    this->groundView = groundView;
}

void CharacterView::setPowerView(PowerView* powerView)
{
    this->powerView = powerView;
}

void CharacterView::setEnemyView(EnemyView* enemyView)
{
    this->enemyView = enemyView;
}

void CharacterView::setMeatView(MeatView* meatView)
{
    this->meatView = meatView;
}

void CharacterView::setEndLevelView(EndLevelView* endLevelView)
{
    this->endLevelView = endLevelView;
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
        std::vector<MovableObject*> grounds = this->groundView->getObjects();
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
        if(powerView->getIsInFire())
        {
            std::cout << "Luffy is in fire" << std::endl;
            checkCollisionWithEnemies();
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
            std::vector<MovableObject*> grounds = this->groundView->getObjects();
            //Put it at the right height
            this->character.jump(grounds.at(index)->getY() - this->character.getY() - 64);
            //Stop the jump
            this->jumpDone = false;
            this->character.setJumping(false);
            //Put the sprite at the new positions
            this->characterSprite.setPosition(this->xPos, this->character.getY());

            return;
        }
        checkCollisionWithEnemies(2);
        checkCollisionWithPowers();
        checkCollisionWithMeats();
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
    std::vector<MovableObject*> grounds = this->groundView->getObjects();
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
        powerView->assignPower(i);
        std::cout << "Power view : " << powerView->str() << std::endl;
        return i;
    }
    return -1;
}

const int CharacterView::checkCollisionWithEnemies(int movement)
{
    std::vector<Enemy*> enemies = this->enemyView->getEnemys();
    time_t now;
    now = time(NULL);
    if(now - momentCollision >= 3){
        character.setInvincible(false);
    }

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
            case 2:
                newY -= 4.f;
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

        if(movement == 1 || movement == 0){
             momentCollision = time(NULL);
             std::cout << "Collision with the enemy !!! on side" << std::endl;
             if(powerView->getIsInFire()) {
                enemyView->killEnemy(i);
             }
             else {
                    if(character.isInvincible() == false){
                        character.takeDamage();
                        character.setInvincible(true);
                    }

             }

             //this->invincibility(2);
        } else {
            std::cout << "Collision with the enemy !!! on top" << std::endl;
            enemyView->killEnemy(i);
        }

        std::cout << "Collision with the enemy !!!" << std::endl;
        return i;
    }
    return -1;
}

const int CharacterView::checkCollisionWithMeats(int movement)
{
    std::vector<Meat*> meats = this->meatView->getMeats();

    for(size_t i=0; i<meats.size(); i++)
    {
        int newX = meats.at(i)->getX();
        int newY = meats.at(i)->getY();
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
        std::cout << "Collision with meat !" << std::endl;
        meatView->eatMeat(i);
        character.gainLife();
        std::cout << "Meat view : " << meatView->str() << std::endl;
        return i;
    }
    return -1;
}

const int CharacterView::checkCollisionWithEndLevel(int movement)
{
    std::vector<EndLevel*> endLevels = this->endLevelView->getEndLevels();

    for(size_t i=0; i<endLevels.size(); i++)
    {
        int newX = endLevels.at(i)->getX();
        int newY = endLevels.at(i)->getY();
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
        std::cout << "Collision with EndLevel !" << std::endl;
        this->win = true;
        std::cout << "EndLevel view : " << endLevelView->str() << std::endl;
        return i;
    }
    return -1;
}

Character CharacterView::getCharacter() const {
    return character;
}

void CharacterView::invincibility(int seconds)
{
    for(auto runUntil = std::chrono::system_clock::now() + std::chrono::seconds(seconds);
        std::chrono::system_clock::now() < runUntil;)
    {
        std::cout << "Hi" << std::endl;
    }
}
