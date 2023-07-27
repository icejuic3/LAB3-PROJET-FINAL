#include "QDynamicEntities.h"





QPainterPath QRabbit::shape() const
{
	return QPainterPath();
}

void QRabbit::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(mQPen);
	painter->setBrush(mQBrush);
	painter->drawPath(mQEntityShape);

}


QDynamicEntities::QDynamicEntities()
	: mMaxSpeed{}
	, mCurrentSpeed{}
	, mMaxHealth{}
	, mCurrentHealth{}
	, mMaxHunger{}
	, mCurrentHunger{}
	, mAttackValue{}
	, mMaxAge{}
	, mCurrentAge{}
	, mInHeat{}
	, mQRabbits{}
	, mQWolves{}
	, mQDeers{}

{
}

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
	qreal legWidth{1};
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

void QWolf::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(mQPen);
	painter->setBrush(mQBrush);
	painter->drawPath(mQEntityShape);

}
