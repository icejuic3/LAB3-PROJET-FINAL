#pragma once

#include "QEntity.h"


class QDynamicEntity : public QEntity
{

	// dynamic cast 
	

public:	

	QDynamicEntity(QPointF const& position = QPointF(), qreal scale = 1.0, qreal speed = 1.0, qreal initialOrientationDegrees = 0.0, QBrush const& brush = Qt::white, QEntity* parent = nullptr);





	//les fonctions que les animaux partagent en commun

	bool isAlive() override;




	static qreal wander(qreal value, qreal begin, qreal end);
	void wander(QPointF& point);	//priotite
	//








	//QList<QDynamicEntities*> mDynamicEntities; //liste de toutes les animaux

	//void DynamicEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange);		//fonction qui verifie les animaux a proximite
	
	
	//void seekFood(QList<QGraphicsItem*>& dynamicEntityInRange);						//cherche nourriture
	

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
	QPointF mNewPosition;
	qreal mNewOrientation;

};


class QWolf : public QDynamicEntity
{
	
public:

	QWolf(QPointF const& initialPosition, qreal scale = 1.0, qreal speed = 1.0, qreal initialOrientationDegrees = 0.0, QBrush const& brush = Qt::white, QDynamicEntity* parent = nullptr);
	~QWolf() override = default;



	/******************Fonctions visuel***************************/



	/*******************Fonctions logiques*****************************************/
	void advance(int phase) override;     //prio



	//QDynamicEntities PreyInRange(QList<>);		//retourne la proie la plus proche
	

	/*************************************************************/

	


};

//class QRabbit : public QDynamicEntity
//{
//	bool isAlive(QList<QGraphicsItem*>& predatorList) override;
//
//	void wander() override;
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
