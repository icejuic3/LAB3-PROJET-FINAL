#include "QStaticEntity.h"




QStaticEntity::QStaticEntity(QPointF const& position, QGraphicsItem* parent)
	: QEntity(position, parent),
	mMaxFoodValue(0.0),
	mCurrentFoodValue(0.0),
	mGrowingSpeed(0.0),
	mCurrentMaturationStage(0.0),
	mReadyToEat(false),
	mIsEdible(false),
	mGrows(false)
{
}



QHerb::QHerb(QPointF const& initialPosition, qreal scale, QBrush const& brush, QStaticEntity* parent)
	:	QStaticEntity(initialPosition, parent),
		mBrush(brush)
{
	mShape << QPointF(0, 0) << QPointF(1, 0) << QPointF(1, 1) << QPointF(0, 1);	//affiche un petit carre pour representer l'herbe

	setPos(50,50);
	setScale(scale);

}

void QHerb::setColor(QBrush const& brush)
{
	mBrush = brush;
}

QRectF QHerb::boundingRect() const
{
	return mShape.boundingRect();
}

void QHerb::staticEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange) {

}
QPainterPath QHerb::opaqueArea() const
{
	return QPainterPath();
}
void QHerb::advance(int phase)
{
}
bool QHerb::isAlive()
{
	return true;
}


void QHerb::checkStatus(QList<QGraphicsItem*>& predatorList)
{
}

void QHerb::dynamicEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange)
{
}

QList<QGraphicsItem*> QHerb::entitiesInRange()
{
	return QList<QGraphicsItem*>();
}

void QHerb::detectCollision(QList<QGraphicsItem*>& dynamicEntityInRange)
{
}

void QHerb::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(Qt::NoPen);
	painter->setBrush(mBrush);
	painter->drawPolygon(mShape);
}

//bool QCarot::isAlive()
//{
//	return false;
//}

//bool QBody::isAlive()
//{
//	return false;
//}
