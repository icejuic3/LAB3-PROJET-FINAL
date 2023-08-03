#include "QStaticEntity.h"




QStaticEntity::QStaticEntity(QPointF const& position, qreal scale, QBrush const& brush, QEntity* parent)
	: QEntity(position, scale, brush, parent),
	mMaxFoodValue(0.0),
	mCurrentFoodValue(0.0),
	mGrowingSpeed(0.0),
	mCurrentMaturationStage(0.0),
	mReadyToEat(false),
	mIsEdible(false),
	mGrows(false)
{


}

bool QStaticEntity::isAlive()
{
	return true;
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


