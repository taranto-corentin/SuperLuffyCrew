#include "EnemyView.h"

EnemyView::EnemyView()
{

}

EnemyView::~EnemyView()
{
    //dtor
}

EnemyView::EnemyView(const EnemyView& other): MovableObjectView::MovableObjectView(other)
{
    //copy ctor
}

EnemyView& EnemyView::operator=(const EnemyView& rhs)
{
    if (this != &rhs){
        MovableObjectView::operator=(rhs);
    }
    return *this;
}

//Setter
void EnemyView::setPowerView(PowerView* powerView)
{
    this->powerView = powerView;
}

//The character kills the enemy at the 'index' position
void EnemyView::killEnemy(int index)
{
    this->powerView->turnOffLuffy(index);
    this->removeObject(this->getObjects().at(index));
}

//To String
const std::string EnemyView::str() const
{
    return "Enemy view";
}

