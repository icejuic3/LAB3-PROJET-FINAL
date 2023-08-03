#pragma once

#include <QGraphicsItem>
#include "QEntity.h"



class QStaticEntity : public QEntity
{

public:

	QStaticEntity(QPointF const& position = QPointF(), qreal scale = 1.0, QBrush const& brush = Qt::white, QEntity* parent = nullptr);
	~QStaticEntity() override = default;

	/***************Fonction visuelle************************/


	/*********************************************************/
	bool isAlive() override;

	//virtual void grow() = 0;

	qreal mMaxFoodValue;
	qreal mCurrentFoodValue;

	qreal mGrowingSpeed;
	qreal mCurrentMaturationStage;


protected:

	bool mReadyToEat;
	bool mIsEdible;
	bool mGrows;

};


class QHerb : public QStaticEntity
{
public:


	QHerb(QPointF const& position, qreal scale = 1.0, QBrush const& brush = Qt::white, QStaticEntity* parent = nullptr);
	~QHerb() override = default;
	
	

	void advance(int phase) override;






	/**************************Les fonctions visuelles***********************************************/



	//void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	//void setColor(QBrush const& brush);
	//QRectF boundingRect() const override;

	//void staticEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange) override;


	/*****************les fonction logiques*******************/
	//void advance(int phase) override;
	
	//QPainterPath opaqueArea() const override;




	//void checkStatus(QList<QGraphicsItem*>& predatorList) override;
	//void dynamicEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange) override;
	//QList<QGraphicsItem*> entitiesInRange() override;
	//void detectCollision(QList<QGraphicsItem*>& dynamicEntityInRange) override;
protected:

	

};


//class QCarot : public QStaticEntity
//{
//
//	QCarot();
//
//public:
//
//	QPainterPath shape() const override;
//	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
//	QPainterPath opaqueArea() const override;
//
//	void advance(int phase) override;
//	void checkStatus(QList<QGraphicsItem*>& predatorList) override;
//	bool isAlive() override;
//	QList<QGraphicsItem*> entitiesInRange() override;
//
//	void detectCollision(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//
//};


//class QBody : public QStaticEntity 
//{
//
//	QBody();
//
//public:
//
//	//QPainterPath shape() const override;
//	//void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
//	//QPainterPath opaqueArea() const override;
//
//	void advance(int phase) override;
//	void checkStatus(QList<QGraphicsItem*>& predatorList) override;
//	bool isAlive() override;
//	QList<QGraphicsItem*> entitiesInRange() override;
//
//	void detectCollision(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//
//};
//
//
//class QExcrement: public QStaticEntity
//{
//};