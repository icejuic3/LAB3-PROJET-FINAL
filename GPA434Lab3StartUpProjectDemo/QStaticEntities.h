#pragma once

#include <QGraphicsItem>
#include "QEntities.h"



class QStaticEntities : public QEntities
{

public:

	QStaticEntities(QEntities* parent);
	//QList<QHerb*> mHerbs;
	//QList<QCarot*> mCarrots;
	//QList<QBody*> mBodies;
	//QList<QExcrement*> mFeces;

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


class QHerb : public QStaticEntities
{
public:

	QHerb(QPointF const& initialPosition = QPointF(), qreal scale = 1.0, QBrush const& brush = Qt::white, QStaticEntities*parent = nullptr);
	~QHerb() override = default;
	QHerb(QHerb const&) = default;
	QHerb& operator = (QHerb const&) = delete;


	/**************************Les fonctions visuelles***********************************************/

	//QPainterPath shape() const override;
	//QPainterPath opaqueArea() const override;

	void setColor(QBrush const& brush);
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;


	/*****************les fonction logiques*******************/
	//void advance(int phase) override;
	//bool isAlive(QList<QGraphicsItem*>& mHerb) override;

	//void detectCollision(QList<QGraphicsItem*>& dynamicEntityInRange) override;



protected:


	// La couleur de fond
	QBrush mBrush;
	// La forme 
	QPolygonF mShape;


};

//
//class QCarot : public QStaticEntities
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
//	bool isAlive(QList<QGraphicsItem*>& predatorList) override;
//	QList<QGraphicsItem*> entitiesInRange() override;
//
//	void detectCollision(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//
//};
//
//
//class QBody : public QStaticEntities 
//{
//
//	QBody();
//
//public:
//
//	QPainterPath shape() const override;
//	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
//	QPainterPath opaqueArea() const override;
//
//	void advance(int phase) override;
//	void checkStatus(QList<QGraphicsItem*>& predatorList) override;
//	bool isAlive(QList<QGraphicsItem*>& predatorList) override;
//	QList<QGraphicsItem*> entitiesInRange() override;
//
//	void detectCollision(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//
//};
//
//
//class QExcrement: public QStaticEntities
//{
//};