#include "CharacterView.h"

CharacterView::CharacterView()
{
    //Init the character
    this->startingY = 472.f;
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
    for(int i=0; i<this->NB_TYPE_MOVEMENT; i++)
    {
        for(int j=0; j<this->NB_IMAGES_PER_MOVEMENT; j++)
        {
            this->characterTextures[i][j] = new sf::Texture();
            this->characterTextures[i][j]->loadFromImage(characterImages[i][j]);
        }
    }

    //Initialization of the sprite
    this->characterSprite.setTexture(*(characterTextures[1][0]));

    //Defining the position of the sprite
    this->characterSprite.setPosition(this->XPOS, this->character.getY());
}

CharacterView::~CharacterView()
{
    //Clear the list of textures to avoid memory leaks
    for(int i=0; i<this->NB_TYPE_MOVEMENT; i++)
    {
        for(int j=0; j<this->NB_IMAGES_PER_MOVEMENT; j++)
        {
            delete this->characterTextures[i][j];
            this->characterTextures[i][j] = nullptr;
        }
    }
}

CharacterView::CharacterView(const CharacterView& other)
{
    //Copy of the game logic elements
    this->startingY = other.startingY;
    this->character = other.character;
    this->jumpDone = other.jumpDone;

    //Copy of all the view elements for the collisions
    this->groundView = other.groundView;
    this->enemyView = other.enemyView;
    this->powerView = other.powerView;
    this->meatView = other.meatView;
    this->endLevelView = other.endLevelView;

    //Copy the textures
    for(int i=0; i<this->NB_TYPE_MOVEMENT; i++)
    {
        for(int j=0; j<NB_IMAGES_PER_MOVEMENT; j++)
        {
            this->characterTextures[i][j] = new sf::Texture(*(other.characterTextures[i][j]));
        }
    }

    //Copy the sprite and set it to its initial state
    this->characterSprite = other.characterSprite;
    this->characterSprite.setTexture(*(characterTextures[1][0]));
}

CharacterView& CharacterView::operator=(const CharacterView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    //Copy of the game logic elements
    this->startingY = rhs.startingY;
    this->character = rhs.character;
    this->jumpDone = rhs.jumpDone;

    //Copy of all the view elements for the collisions
    this->groundView = rhs.groundView;
    this->enemyView = rhs.enemyView;
    this->powerView = rhs.powerView;
    this->meatView = rhs.meatView;
    this->endLevelView = rhs.endLevelView;

    //Copy the textures
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            this->characterTextures[i][j] = new sf::Texture(*(rhs.characterTextures[i][j]));
        }
    }

    //Copy the sprite and set it to its initial state
    this->characterSprite = rhs.characterSprite;
    this->characterSprite.setTexture(*(characterTextures[1][0]));

    return *this;
}

//Getter
int CharacterView::getAdvancementState()const
{
    return advancementState;
}

//Setters
void CharacterView::setAdvancementState(int advancementState)
{
    this->advancementState = advancementState;
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

//Render the character in the window
void CharacterView::render(sf::RenderWindow* window)
{
    this->characterSprite.setPosition(this->XPOS, this->character.getY());
    window->draw(this->characterSprite);
}

/*
Check the movements of the character, change the texture of the character in function of the movement he does.
Check also the collision with enemies when the character is on fire (after he took a power)
*/

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
            //Condition to know if there is something under the character
            if(((this->XPOS <= grounds.at(i)->getX() + 64 && this->XPOS >= grounds.at(i)->getX()) ||
               (this->XPOS - this->CHARACTER_WIDTH <= grounds.at(i)->getX() && this->XPOS + this->CHARACTER_WIDTH >= grounds.at(i)->getX())) &&
               this->character.getY() + 64 == grounds.at(i)->getY())
            {
                hasToFall = false;
            }
        }
        //If there is nothing then make the character fall and quit the method
        if(hasToFall)
        {
            this->character.setJumping(true);
            this->jumpDone = true;
            return;
        }

        //Change the posture of the character in function of the current one
        const sf::Texture* texture = characterSprite.getTexture();
        if(texture == this->characterTextures[movement][0])
        {
            this->characterSprite.setTexture(*(this->characterTextures[movement][1]));
        }
        else if(texture == this->characterTextures[movement][1])
        {
            this->characterSprite.setTexture(*(this->characterTextures[movement][2]));
        }
        else
        {
            this->characterSprite.setTexture(*(this->characterTextures[movement][0]));
        }
        //Check the collision when the character is on fire
        if(powerView->getIsInFire())
        {
            checkCollisionWithEnemies();
        }
    }
}

//Make the character jump and check the collisions during the jump
void CharacterView::jump()
{
    //Setting the attribute jumping to true if it is not the case already
    if(!this->character.isJumping())
    {
        this->character.setJumping(true);
    }
    //Check if the character should has reached its highest point
    if(this->startingY - this->JUMP_HEIGHT >= this->character.getY())
    {
        this->jumpDone = true;
    }

    //If the character hasn't reached its highest point
    if(!this->jumpDone)
    {
        int index = this->checkCollision();
        //If the character has collided with an obstacle while falling stop the jump and make him fall and quit the method
        if(index != -1)
        {
            this->jumpDone = true;
            this->character.jump(7);
            return;
        }
        //Otherwise keep making the character go higher and update the position of the sprite
        this->character.jump(-6);
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
            //Set the startingY at the new Y of the character
            this->startingY = this->character.getY();

            return;
        }
        //Check any potential collision and keep the jump going
        checkCollisionWithEnemies(2);
        checkCollisionWithPowers();
        checkCollisionWithMeats();
        this->character.jump(7);
    }
}

const bool CharacterView::isJumping() const
{
    return this->character.isJumping();
}

//Check collisions with obstacles
const int CharacterView::checkCollision(int movement)
{
    //Get all the obstcales
    std::vector<MovableObject*> grounds = this->groundView->getObjects();
    return this->getCollisionIndex(grounds, movement);
}

//Check collisions with powers
const int CharacterView::checkCollisionWithPowers(int movement)
{
    //Get all the powers
    std::vector<MovableObject*> powers = this->powerView->getObjects();

    int index = this->getCollisionIndex(powers, movement);
    if(index != -1)
    {
        powerView->assignPower(index);
    }
    return index;
}

//Check collisions with enemies
const int CharacterView::checkCollisionWithEnemies(int movement)
{
    //Get all the enemies
    std::vector<MovableObject*> enemies = this->enemyView->getObjects();

    for(size_t i=0; i<enemies.size(); i++)
    {
        //Determine the new position of the character
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
        //Check if there is a collision
        if(this->XPOS + this->CHARACTER_WIDTH <= newX || this->XPOS >= newX + this->CHARACTER_WIDTH)
        {
            continue;
        }

        if(this->character.getY() + 64 <= newY || newY + 64 <= this->character.getY())
        {
            continue;
        }

        //Check if the character enters in collision with an enemy on the side or on the top
        if(movement == 1 || movement == 0){
             momentCollision = time(NULL);
             if(powerView->getIsInFire()) {
//SOUND
                /*if ( buffer.loadFromFile("assets/kill.wav") )
                {
                    sound = sf::Sound(buffer);
                    sound.play();
                }
                else
                {
                std::cout << "couldn't load kill sound effect!";
                }*/
//----
                enemyView->killEnemy(i);
             }
             else {
//SOUND
                if ( buffer.loadFromFile("assets/dammaged.wav") )
                {
                    sound = sf::Sound(buffer);
                    sound.play();
                }
                else
                {
                std::cout << "couldn't load dammage sound effect!";
                }
//----
                character.takeDamage();
                enemyView->killEnemy(i);
             }
        } else {
//SOUND
            /*if ( buffer.loadFromFile("assets/kill.wav") )
            {
                sound = sf::Sound(buffer);
                sound.play();
            }
            else
            {
            std::cout << "couldn't load kill sound effect!";
            }*/
//----
            enemyView->killEnemy(i);
        }
        if(character.getLifePoint() <= 0){
            setAdvancementState(0);
            character.setLifePoint(3);
        }

        return i;
    }
    return -1;
}

//Check collisions with the meat
const int CharacterView::checkCollisionWithMeats(int movement)
{
    //Get all the meat
    std::vector<MovableObject*> meats = this->meatView->getObjects();

    for(size_t i=0; i<meats.size(); i++)
    {
        //Get the new position of the meat
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
        //Check if there is a collision
        if(this->XPOS + this->CHARACTER_WIDTH <= newX || this->XPOS >= newX + this->CHARACTER_WIDTH)
        {
            continue;
        }
        if(this->character.getY() + 64 <= newY || newY + 64 <= this->character.getY())
        {
            continue;
        }
//SOUND
        if ( buffer.loadFromFile("assets/upLife.wav") )
        {
            sound = sf::Sound(buffer);
            sound.play();
        }
        else
        {
        std::cout << "couldn't load dammage sound effect!";
        }
//----
        meatView->eatMeat(i);
        character.gainLife();
        return i;
    }
    return -1;
}

//Check collisions with the end of the level (the boat)
const int CharacterView::checkCollisionWithEndLevel(int movement)
{
    //Get the endLevel
    std::vector<MovableObject*> endLevels = this->endLevelView->getObjects();

    for(size_t i=0; i<endLevels.size(); i++)
    {
        //Determine the new position of the endLevel
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
        //Check if there is a collision or not
        if(this->XPOS + this->CHARACTER_WIDTH <= newX || this->XPOS >= newX + this->CHARACTER_WIDTH)
        {
            continue;
        }
        if(this->character.getY() + 64 <= newY || newY + 64 <= this->character.getY())
        {
            continue;
        }
        this->advancementState = 5;
        character.setLifePoint(3);
        return i;
    }
    return -1;
}

//Getter
Character CharacterView::getCharacter() const {
    return character;
}

const int CharacterView::getCollisionIndex(std::vector<MovableObject*> objects, int movement)
{
    for(size_t i=0; i<objects.size(); i++)
    {
        //Determine the new position of the object based on its movement
        int newX = objects.at(i)->getX();
        int newY = objects.at(i)->getY();
        switch(movement)
        {
            case 0:
                newX += 4.f;
                break;
            case 1:
                newX -= 4.f;
                break;
        }
        //Determine if the character collided with an obstacle
        if(this->XPOS + this->CHARACTER_WIDTH <= newX || this->XPOS >= newX + this->CHARACTER_WIDTH)
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
