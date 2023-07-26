#pragma once

#include <QGraphicsItem>

class QEntities : public QGraphicsItem
{


public:
	virtual QPainterPath shape() const = 0;
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) = 0;
	virtual QPainterPath opaqueArea() const = 0;

	virtual void advance(int phase) = 0;

	virtual bool isAlive(QList<QGraphicsItem*>& predatorList) = 0;
	virtual void checkStatus(QList<QGraphicsItem*>& predatorList) = 0;

	virtual QList<QGraphicsItem*> entitiesInRange()=0;
	virtual void staticEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange)=0;
	virtual void dynamicEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange)=0;
	virtual void detectCollision(QList<QGraphicsItem*>& dynamicEntityInRange) = 0;

	QString mFamilyIdd;

};

