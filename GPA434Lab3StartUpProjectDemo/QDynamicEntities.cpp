#include "QDynamicEntities.h"



QDynamicEntities::QDynamicEntities(QPointF const& position, QEntities* parent)
	:QEntities(position,parent),
	mCurrentAge{1},	//tout les animaux vont etre initialise avec ces valeurs
	mMaxAge{30},
	mMaxHunger{30},
	mCurrentHunger{mMaxHunger},
	mCurrentSpeed{1},
	mMaxSpeed{5},
	mMaxHealth{5},
	mCurrentHealth{mMaxHealth},
	mAttackValue{1},
	mInHeat{0}

{
	
	
}

bool QDynamicEntities::isAlive()
{

	if (mCurrentAge == mMaxAge || mCurrentHunger == 0) {

		return false;
	}

	return true;
	
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

qreal QDynamicEntities::getHealth() const
{
	return mCurrentHealth;
}

bool QDynamicEntities::getHeat() const
{
	return mInHeat;
}




/*****************************************Fonction Loup***********************************************************************/


QWolf::QWolf(QPointF const& position, QDynamicEntities* parent)
	:QDynamicEntities(position,parent)
{

	setColor(Qt::red);
	mShape << QPointF(0, 0) << QPointF(1, 0) << QPointF(0.5, 1);	//affiche un petit triangle pour representer le loup

	setScale(15);
	
}

void QWolf::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(Qt::NoPen);
	painter->setBrush(mBrush);
	painter->drawPolygon(mShape);

}

void QWolf::setColor(QBrush const& brush)
{
	mBrush = brush;
}

QRectF QWolf::boundingRect() const
{
	return mShape.boundingRect();
}








/*******************************************************************************************************************/
//
//
//QPainterPath QDeer::shape() const
//{
//	return QPainterPath();
//}
//
//void QDeer::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
//{
//
//	painter->setPen(mQPen);
//	painter->setBrush(mQBrush);
//	painter->drawPath(mQEntityShape);
//}
//
//QPainterPath QWolf::shape()
//{
//	qreal legWidth{ 1 };
//	qreal legHeight{ 3 };
//	qreal bodyWidth{ 5 };
//	qreal bodyLength{ 10 };
//	qreal headWidth{ 10 };
//	qreal headLength{ 10 };
//
//	mQEntityShape.lineTo(bodyLength, 0);
//	mQEntityShape.lineTo(bodyLength, bodyWidth);
//	mQEntityShape.lineTo(0, bodyWidth);
//	mQEntityShape.closeSubpath();
//
//}
//