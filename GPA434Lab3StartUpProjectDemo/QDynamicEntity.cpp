//#include "QDynamicEntity.h"
//
//
//
//QDynamicEntity::QDynamicEntity(QPointF const& position, QEntity* parent)
//	:QEntity(position,parent),
//	mCurrentAge{1},	//tout les animaux vont etre initialise avec ces valeurs
//	mMaxAge{30},
//	mMaxHunger{30},
//	mCurrentHunger{mMaxHunger},
//	mCurrentSpeed{1},
//	mMaxSpeed{5},
//	mMaxHealth{5},
//	mCurrentHealth{mMaxHealth},
//	mAttackValue{1},
//	mInHeat{0}
//
//{
//	
//	
//}
//
//bool QDynamicEntity::isAlive()
//{
//
//	if (mCurrentAge == mMaxAge || mCurrentHunger == 0) {
//
//		return false;
//	}
//
//	return true;
//	
//}
//
//
//
//void QDynamicEntity::setAge(qreal age)
//{
//	mCurrentAge = age;
//}
//
//void QDynamicEntity::setHunger(qreal hunger)
//{
//	mCurrentHunger = hunger;
//}
//
//void QDynamicEntity::setSpeed(qreal speed)
//{
//	mCurrentSpeed = speed;
//}
//
//void QDynamicEntity::setHealth(qreal health)
//{
//	mCurrentHealth = health;
//}
//
//void QDynamicEntity::setHeat(bool heat)
//{
//	mInHeat = heat;
//}
//
//qreal QDynamicEntity::getAge() const
//{
//	return mCurrentAge;
//}
//
//qreal QDynamicEntity::getHunger() const
//{
//	return mCurrentHunger;
//}
//
//qreal QDynamicEntity::getSpeed() const
//{
//	return mCurrentSpeed;
//}
//
//qreal QDynamicEntity::getHealth() const
//{
//	return mCurrentHealth;
//}
//
//bool QDynamicEntity::getHeat() const
//{
//	return mInHeat;
//}




/*****************************************Fonction Loup***********************************************************************/


//QWolf::QWolf(QPointF const& position, QDynamicEntity* parent)
//	:QDynamicEntity(position,parent)
//{
//
//	setColor(Qt::red);
//	mShape << QPointF(0, 0) << QPointF(1, 0) << QPointF(0.5, 1);	//affiche un petit triangle pour representer le loup
//
//	setScale(15);
//	
//}

//void QWolf::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
//{
//	painter->setPen(Qt::NoPen);
//	painter->setBrush(mBrush);
//	painter->drawPolygon(mShape);
//
//}
//
//void QWolf::setColor(QBrush const& brush)
//{
//	mBrush = brush;
//}
//
//QRectF QWolf::boundingRect() const
//{
//	return mShape.boundingRect();
//}








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