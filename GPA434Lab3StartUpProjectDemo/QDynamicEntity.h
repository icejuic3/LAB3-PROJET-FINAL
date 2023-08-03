#pragma once

#include "QEntity.h"


class QDynamicEntity : public QEntity
{
public:	

	QDynamicEntity(QPointF const& position = QPointF(), qreal age=1.0, qreal scale = 1.0, qreal speed = 1.0, qreal initialOrientationDegrees = 0.0, QBrush const& brush = Qt::white, QEntity* parent = nullptr);
	~QDynamicEntity() override = default;




	//les fonctions que les animaux partagent en commun

	bool isAlive() override;

	static qreal warp(qreal value, qreal begin, qreal end);
	void warp(QPointF& point);
	
	void wander(int phase);
	virtual void ageIncrement()=0;



	//QList<QDynamicEntities*> mDynamicEntities; //liste de toutes les animaux
	//void DynamicEntitiesInRange(QList<QGraphicsItem*>& entitiesInRange);		//fonction qui verifie les animaux a proximite
	//void seekFood(QList<QGraphicsItem*>& dynamicEntityInRange);						//cherche nourriture
	//void pickNearest(QList<QGraphicsItem*>& dynamicEntityInRange);
	//void mate(QList<QGraphicsItem*>& dynamicEntityInRange);
	//void approach(QList<QGraphicsItem*>& dynamicEntityInRange);
	//void consumeNutrient(QList<QGraphicsItem*>& dynamicEntityInRange);
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

	QWolf(QPointF const& position, qreal age=1.0 , qreal scale = 1.0, qreal speed = 0, qreal initialOrientationDegrees = 0.0, QBrush const& brush = Qt::white, QDynamicEntity* parent = nullptr);
	~QWolf() override = default;


	
	void advance(int phase) override;    
	void ageIncrement() override;

};


class QRabbit : public QDynamicEntity
{

public:

	QRabbit(QPointF const& position, qreal age = 1.0, qreal scale = 1.0, qreal speed = 0, qreal initialOrientationDegrees = 0.0, QBrush const& brush = Qt::white, QDynamicEntity* parent = nullptr);
	~QRabbit() override = default;
	

	void advance(int phase) override;
	void ageIncrement() override;



};




//class QDeer : public QDynamicEntities
//{
//
//
//
//};
