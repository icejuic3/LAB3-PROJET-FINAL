#include "QDynamicEntity.h"



QDynamicEntity::QDynamicEntity(QPointF const& position, qreal scale, qreal speed, qreal initialOrientationDegrees, QBrush const& brush, QEntity* parent)
	:QEntity(position, scale, brush, parent),
	mCurrentAge{1},	//tout les animaux vont etre initialise avec ces valeurs
	mMaxAge{30},
	mMaxHunger{30},
	mCurrentHunger{mMaxHunger},
	mCurrentSpeed{speed},
	mMaxSpeed{5},
	mMaxHealth{5},
	mCurrentHealth{mMaxHealth},
	mAttackValue{1},
	mInHeat{0}

{
	setRotation(initialOrientationDegrees);
	
}

bool QDynamicEntity::isAlive()
{

	if (mCurrentAge == mMaxAge || mCurrentHunger == 0) {

		return false;
	}

	return true;
	
}

void QDynamicEntity::wander(QList<QGraphicsItem*>& dynamicEntityInRange)
{
}



void QDynamicEntity::setAge(qreal age)
{
	mCurrentAge = age;
}

void QDynamicEntity::setHunger(qreal hunger)
{
	mCurrentHunger = hunger;
}

void QDynamicEntity::setSpeed(qreal speed)
{
	mCurrentSpeed = speed;
}

void QDynamicEntity::setHealth(qreal health)
{
	mCurrentHealth = health;
}

void QDynamicEntity::setHeat(bool heat)
{
	mInHeat = heat;
}

qreal QDynamicEntity::getAge() const
{
	return mCurrentAge;
}

qreal QDynamicEntity::getHunger() const
{
	return mCurrentHunger;
}

qreal QDynamicEntity::getSpeed() const
{
	return mCurrentSpeed;
}

qreal QDynamicEntity::getHealth() const
{
	return mCurrentHealth;
}

bool QDynamicEntity::getHeat() const
{
	return mInHeat;
}




/*****************************************Fonction Loup***********************************************************************/


QWolf::QWolf(QPointF const& position, qreal scale, qreal speed, qreal initialOrientationDegrees, QBrush const& brush, QDynamicEntity* parent)
	:QDynamicEntity(position,scale,initialOrientationDegrees,speed,brush,parent)
{

	mShape << QPointF(0, 0) << QPointF(1, 0) << QPointF(0.5, 1);	//affiche un petit triangle pour representer le loup

}





/*******************************************************************************************************************/

