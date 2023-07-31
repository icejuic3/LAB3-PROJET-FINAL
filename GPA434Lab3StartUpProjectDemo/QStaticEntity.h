#pragma once

#include <QGraphicsItem>
#include "QEntity.h"



class QStaticEntity : public QEntity
{

public:

	QStaticEntity(QPointF const& position, QGraphicsItem* parent);

	/***************Fonction visuelle************************/





	/*********************************************************/


	//virtual void grow() = 0;

	qreal mMaxFoodValue;
	qreal mCurrentFoodValue;

	qreal mGrowingSpeed;
	qreal mCurrentMaturationStage;


private:


	bool mReadyToEat;
	bool mIsEdible;
	bool mGrows;

};


class QHerb : public QStaticEntity
{
public:



	QHerb(QPointF const& initialPosition = QPointF(), qreal scale = 1.0, QBrush const& brush = Qt::white, QStaticEntity *parent = nullptr);
	~QHerb() override = default;
	QHerb(QHerb const&) = default;
	QHerb& operator = (QHerb const&) = delete;


	/**************************Les fonctions visuelles***********************************************/

	//QPainterPath shape() const override;
	//QPainterPath opaqueArea() const override;

	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	void setColor(QBrush const& brush);
	QRectF boundingRect() const override;

	void staticEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange) override;


	/*****************les fonction logiques*******************/
	void advance(int phase) override;
	bool isAlive() override;
	QPainterPath opaqueArea() const override;

	void checkStatus(QList<QGraphicsItem*>& predatorList) override;
	void dynamicEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange) override;
	QList<QGraphicsItem*> entitiesInRange() override;
	void detectCollision(QList<QGraphicsItem*>& dynamicEntityInRange) override;
protected:

	// La couleur de fond
	QBrush mBrush;
	// La forme 
	QPolygonF mShape;

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