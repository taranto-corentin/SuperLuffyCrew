#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H

#include "Character.h"
#include "GroundView.h"
#include "EnemyView.h"
#include "PowerView.h"
#include "MeatView.h"
#include "EndLevelView.h"

class CharacterView
{
    private:
        //Game logic
        Character character;
        bool jumpDone;
        GroundView* groundView;
        EnemyView* enemyView;
        PowerView* powerView;
        MeatView* meatView;
        EndLevelView* endLevelView;
        int advancementState = 7;
        //Images
        sf::Texture characterTextures[2][3];
        sf::Sprite characterSprite;
        sf::Sprite powerSprite;

        time_t momentCollision;
        //Constants
        const float xPos = 368.f;
        const float jumpHeight = 322.f;
        const float startingY = 472.f;
        const int nbTypeMovement = 2;
        const int nbImagesPerMovement = 3;

        const float characterWidth = 45.f;

    public:
        CharacterView();
        virtual ~CharacterView();
        CharacterView(const CharacterView& other);
        CharacterView& operator=(const CharacterView& rhs);

        //Accessors
        Character getCharacter() const;
        int getAdvancementState()const;
        void setAdvancementState(int advancementState);
        void setGroundView(GroundView* groundView);
        void setPowerView(PowerView* powerView);
        void setEnemyView(EnemyView* enemyView);
        void setMeatView(MeatView* meatView);
        void setEndLevelView(EndLevelView* endLevelView);
        //Methods
        void render(sf::RenderWindow* window);
        void moveCharacter(const int movement);
        void invincibility(int seconds);
        void jump();
        const bool isJumping() const;
        const int checkCollision(int movement=0) const;
        const int checkCollisionWithEnemies(int movement=0);
        const int checkCollisionWithPowers(int movement=0) const;
        const int checkCollisionWithMeats(int movement=0);
        const int checkCollisionWithEndLevel(int movement=0);
        const int checkIfLuffyOrEnemyDie()const;
};

#endif // CHARACTERVIEW_H
