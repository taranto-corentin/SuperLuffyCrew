#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H

#include "Character.h"
#include "GroundView.h"
#include "EnemyView.h"

class CharacterView
{
    private:
        //Game logic
        Character character;
        bool jumpDone;

        GroundView* groundView;
        EnemyView* enemyView;
        //Images
        sf::Texture characterTextures[2][3];
        sf::Sprite characterSprite;

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
        void setGroundView(GroundView* groundView);

        //Methods
        void render(sf::RenderWindow* window);
        void moveCharacter(const int movement);
        void jump();
        const bool isJumping() const;
        const int checkCollision(int movement=0) const;
        const int checkCollisionWithEnemies(int movement=0) const;
};

#endif // CHARACTERVIEW_H
