#include "QStaticEntity.h"



QStaticEntity::QStaticEntity(QPointF const& position, qreal scale, QBrush const& brush, QEntity* parent)
	: QEntity(position, scale, brush, parent),
	mMaxFoodValue(0.0),
	mCurrentFoodValue(0.0),
	mReadyToEat(false),
	mGrows(false)
{

}

bool QStaticEntity::isAlive()
{

	if (mAlive)
	{
		return mAlive;
	}
	else if(!mAlive)
	{
		return false;
	}

}


/*******************************FONCTIONS HERB**********************************************************/
QHerb::QHerb(QPointF const& position, qreal scale, QBrush const& brush, QStaticEntity* parent)
	:	QStaticEntity(position, scale, brush, parent)

		
{
	
	mShape << QPointF(0, 0) << QPointF(1, 0) << QPointF(1, 1) << QPointF(0, 1);	//affiche un petit carre pour representer l'herbe

}

void QHerb::advance(int phase)
{

}


/*******************************FONCTIONS Carrot**********************************************************/
QCarrot::QCarrot(QPointF const& position, qreal scale, QBrush const& brush, QStaticEntity* parent)
	: QStaticEntity(position, scale, brush, parent)


{

	mShape << QPointF(0, 0) << QPointF(1, 0) << QPointF(1, 1) << QPointF(0, 1);	//affiche un petit carre

}


void QCarrot::advance(int phase)
{
}
