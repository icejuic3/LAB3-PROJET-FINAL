#pragma once

#include "Qentities.h"


class QDynamicEntities : public QEntities
{

	// dynamic cast 
	

public:	

	QDynamicEntities(QPointF const& position = QPointF(), QEntities* parent = nullptr);





	//les fonctions que les animaux partagent en commun

	bool isAlive() override;

	//QList<QDynamicEntities*> mDynamicEntities; //liste de toutes les animaux

	//void DynamicEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange);		//fonction qui verifie les animaux a proximite
	//
	//
	//
	//
	//void seekFood(QList<QGraphicsItem*>& dynamicEntityInRange);						//cherche nourriture
	//
	//
	//
	//void wander(QList<QGraphicsItem*>& dynamicEntityInRange);
	//void pickNearest(QList<QGraphicsItem*>& dynamicEntityInRange);
	//void mate(QList<QGraphicsItem*>& dynamicEntityInRange);
	//void approach(QList<QGraphicsItem*>& dynamicEntityInRange);
	//void consumeNutrient(QList<QGraphicsItem*>& dynamicEntityInRange);
	//

	//void sameFamily(QList<QGraphicsItem*>& dynamicEntityInRange, bool sameFamily);	//dans entities?
	//void pickWeakest(QList<QGraphicsItem*>& dynamicEntityInRange) = 0;				//dans wolf?







	/******setter*********/

	void setAge(qreal age);
	void setHunger(qreal hunger);
	void setSpeed(qreal speed);
	void setHealth(qreal health);
	void setHeat(bool heat);

	/*****getter**********/

	qreal getAge() const;
	qreal getHunger() const;
	qreal getSpeed() const;
	qreal getHealth() const;
	bool getHeat() const;
	/***********************/



protected:
	qreal const mMaxAge;
	qreal mCurrentAge;
	qreal const mMaxHunger;
	qreal mCurrentHunger;
	qreal const mMaxSpeed;
	qreal mCurrentSpeed;
	qreal const mMaxHealth;
	qreal mCurrentHealth;
	bool mInHeat;
	qreal const mAttackValue;	// a deplacer dans loup
};


class QWolf : public QDynamicEntities
{
	
public:

	QWolf(QPointF const& position = QPointF(), QDynamicEntities* parent = nullptr);
	~QWolf() override = default;



	/******************Fonctions visuel***************************/

	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	void setColor(QBrush const& brush);
	QRectF boundingRect() const override;


	/*******************Fonctions logiques*****************************************/

	//QDynamicEntities PreyInRange(QList<>);		//retourne la proie la plus proche
	

	/*************************************************************/

	












};

//class QRabbit : public QDynamicEntities
//{
//	bool isAlive(QList<QGraphicsItem*>& predatorList) override;
//
//	void wander(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//	void consumeNutrient(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//	void detectCollision(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//	void advance(int phase) override;
//
//	QList<QGraphicsItem*> entitiesInRange() override;
//	void staticEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange) override;
//	void dynamicEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange) override;
//	void checkStatus(QList<QGraphicsItem*>& predatorList) override;
//	void sameFamily(QList<QGraphicsItem*>& dynamicEntityInRange, bool sameFamily) override;
//
//	void seekFood(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//	void pickWeakest(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//
//	void approach(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//	void mate(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//
//	QPainterPath shape() const override;
//	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
//	QPainterPath opaqueArea() const override;
//
//};
//
//
//class QDeer : public QDynamicEntities
//{
//
//	bool isAlive(QList<QGraphicsItem*>& predatorList) override;
//
//	void wander(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//	void consumeNutrient(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//	void detectCollision(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//	void advance(int phase) override;
//
//	QList<QGraphicsItem*> entitiesInRange() override;
//	void staticEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange) override;
//	void dynamicEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange) override;
//	void checkStatus(QList<QGraphicsItem*>& predatorList) override;
//	void sameFamily(QList<QGraphicsItem*>& dynamicEntityInRange, bool sameFamily) override;
//
//	void seekFood(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//	void pickWeakest(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//
//	void approach(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//	void mate(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//
//	QPainterPath shape() const override;
//	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
//	QPainterPath opaqueArea() const override;
//
//};
