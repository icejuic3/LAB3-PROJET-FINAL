#pragma once
#ifndef QENTITY_H
#define QENTITY_H

#include <QGraphicsItem>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QList>



class QEntity : public QGraphicsItem
{
protected:

	QColor mColor;		//variable pour la couleur de l'entite
	QBrush mBrush;		//variable pour le brush
	QPolygonF mShape;	//variable pour la forme de l'entite
	QPointF mPosition;	//variable pour la position de l'entite
	QPen mQPen;
	
	QList<QGraphicsItem*> mEntitiesInRange;
	QPainterPath mLineOfSight; //distance de vision pour une entite


public:



	QEntity(QPointF const& position = QPointF(), qreal scale = 1.0, QBrush const& brush = Qt::white, QGraphicsItem*parent = nullptr);
	~QEntity() = default;
	

	/***************Fonction visuelle************************/

	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	void setColor(QBrush const& brush);
	QRectF boundingRect() const override;

	/********************Fonction que les animaux et les plantes partagent*************************************/

	virtual bool isAlive() = 0;												//
	const QPointF& getEntityPosition() const;
	//virtual bool isPrey(QEntity const* entity) const = 0;
	//virtual void entitiesInRange() = 0;		//fontion qui detecte les entites dans mon rayon de detection
	
	
	//virtual QList<QGraphicsItem*> entitiesInRange() = 0;
	//virtual void staticEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange) = 0;
	//virtual QPainterPath opaqueArea() const = 0;
	//virtual void advance(int phase) = 0;
	//virtual void checkStatus(QList<QGraphicsItem*>& predatorList) = 0;
	//virtual void dynamicEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange) = 0;
	//virtual void detectCollision(QList<QGraphicsItem*>& dynamicEntityInRange) = 0;
	
};

#endif