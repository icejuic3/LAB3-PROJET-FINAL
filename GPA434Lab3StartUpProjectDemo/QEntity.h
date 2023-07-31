#pragma once
#ifndef QENTITY_H
#define QENTITY_H

#include <QGraphicsItem>
#include <QBrush>
#include <QPen>
#include <QPainter>
class QEntity : public QGraphicsItem
{
protected:


	QString mFamilyId;
	QColor mColor;		//variable pour la couleur de l'entite
	QBrush mBrush;		//variable pour le brush
	QPolygonF mShape;	//variable pour la forme de l'entite
	QPointF mPosition;	//variable pour la position de l'entite

	QPen mQPen;
	//QPainterPath mQEntityShape;


public:
	QEntity(QPointF const& position = QPointF(),QGraphicsItem*parent = nullptr);
	

	/***************Fonction visuelle************************/


	virtual void setColor(QBrush const& brush)=0;
	

	/********************Fonction que les animaux et les plantes partagent*************************************/

	virtual bool isAlive() = 0;												//





	QPointF& getPosition() ;



	virtual QList<QGraphicsItem*> entitiesInRange() = 0;
	virtual void staticEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange) = 0;
	virtual QPainterPath opaqueArea() const = 0;
	virtual void advance(int phase) = 0;
	virtual void checkStatus(QList<QGraphicsItem*>& predatorList) = 0;
	virtual void dynamicEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange) = 0;
	virtual void detectCollision(QList<QGraphicsItem*>& dynamicEntityInRange) = 0;
	
};

#endif