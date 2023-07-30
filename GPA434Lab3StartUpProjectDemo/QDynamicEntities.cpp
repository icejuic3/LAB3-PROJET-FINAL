#include "QDynamicEntities.h"



QDynamicEntities::QDynamicEntities(QEntities* parent)
	:mCurrentAge{1},	//tout les animaux vont etre initialise avec ces valeurs
	mMaxAge{30},

	mCurrentHunger{0},
	mMaxHunger{30},

	mCurrentSpeed{1},
	mMaxSpeed{5},

	mCurrentHealth{5},
	mMaxHealth{5},

	mAttackValue{1},
	mInHeat{0},
	QEntities(parent)

{
	
	
}




QWolf::QWolf(QDynamicEntities* parent)
	:QDynamicEntities(parent)
{
}





/*****************************************Fonction Loup***********************************************************************/
bool QWolf::isAlive(QList<QGraphicsItem*>& wolf)
{


	for (size_t i{}; i < wolf.size(); ++i) {

		if (wolf[i] = 0 || wolf[i].mAge)



	}


	






}














/*******************************************************************************************************************/


QPainterPath QDeer::shape() const
{
	return QPainterPath();
}

void QDeer::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{

	painter->setPen(mQPen);
	painter->setBrush(mQBrush);
	painter->drawPath(mQEntityShape);
}

QPainterPath QWolf::shape()
{
	qreal legWidth{ 1 };
	qreal legHeight{ 3 };
	qreal bodyWidth{ 5 };
	qreal bodyLength{ 10 };
	qreal headWidth{ 10 };
	qreal headLength{ 10 };

	mQEntityShape.lineTo(bodyLength, 0);
	mQEntityShape.lineTo(bodyLength, bodyWidth);
	mQEntityShape.lineTo(0, bodyWidth);
	mQEntityShape.closeSubpath();

}

void QDynamicEntities::setAge(qreal age)
{
	mCurrentAge = age;
}

void QDynamicEntities::setHunger(qreal hunger)
{
	mCurrentHunger = hunger;
}

void QDynamicEntities::setSpeed(qreal speed)
{
	mCurrentSpeed = speed;
}

void QDynamicEntities::setHealth(qreal health)
{
	mCurrentHealth = health;
}

void QDynamicEntities::setHeat(bool heat)
{
	mInHeat = heat;
}

qreal QDynamicEntities::getAge() const
{
	return mCurrentAge;
}

qreal QDynamicEntities::getHunger() const
{
	return mCurrentHunger;
}

qreal QDynamicEntities::getSpeed() const
{
	return mCurrentSpeed;
}
