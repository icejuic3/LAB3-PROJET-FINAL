#pragma once

#include <QGraphicsItem>
#include "QEntities.h"



class QStaticEntities : public QEntities
{

public:

	QStaticEntities();
	QList<QHerb*> mHerbs;
	QList<QCarot*> mCarrots;
	QList<QBody*> mBodies;
	QList<QExcrement*> mFeces;

	virtual void grow() = 0;

private:

	qreal mMaxFoodValue;
	qreal mCurrentFoodValue;

	qreal mGrowingSpeed;
	qreal mCurrentMaturationStage;

	bool mReadyToEat;
	bool mIsEdible;
	bool mGrows;

};



class QHerb : public QStaticEntities
{

	QHerb();

public:

	QPainterPath shape() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
	QPainterPath opaqueArea() const override;

	void advance(int phase) override;
	bool isAlive(QList<QGraphicsItem*>& predatorList) override;

	void detectCollision(QList<QGraphicsItem*>& dynamicEntityInRange) override;


};


class QCarot : public QStaticEntities
{

	QCarot();

public:

	QPainterPath shape() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
	QPainterPath opaqueArea() const override;

	void advance(int phase) override;
	void checkStatus(QList<QGraphicsItem*>& predatorList) override;
	bool isAlive(QList<QGraphicsItem*>& predatorList) override;
	QList<QGraphicsItem*> entitiesInRange() override;

	void detectCollision(QList<QGraphicsItem*>& dynamicEntityInRange) override;

};


class QBody : public QStaticEntities 
{

	QBody();

public:

	QPainterPath shape() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
	QPainterPath opaqueArea() const override;

	void advance(int phase) override;
	void checkStatus(QList<QGraphicsItem*>& predatorList) override;
	bool isAlive(QList<QGraphicsItem*>& predatorList) override;
	QList<QGraphicsItem*> entitiesInRange() override;

	void detectCollision(QList<QGraphicsItem*>& dynamicEntityInRange) override;

};


class QExcrement: public QStaticEntities
{
};