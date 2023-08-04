#pragma once

#include "QEntity.h"
#include "QStaticEntity.h"


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
	

	void entitiesInRange();		//fontion qui detecte les entites dans mon rayon de detection

	void sameFamily();					//fontion pour filtrer les creatures de la meme famille
	void filterPrey();					//fonction filtre pourn les proies


	QEntity* pickNearest();					//retourne l'adresse de l'entite la plus proche?
	void approach(QEntity* targetEntity);					//se deplace vers l'entite la plus proche

	
	virtual void statusChange()=0;
	virtual void seekFood() = 0;						//cherche nourriture

	virtual bool isPrey(QEntity const * entity) const = 0;

	




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

	
	

	QString mPreyId;	
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
	void statusChange() override;
	void seekFood() override;

	bool isPrey(QEntity const* entity) const override;

};


class QRabbit : public QDynamicEntity
{

public:

	QRabbit(QPointF const& position, qreal age = 1.0, qreal scale = 1.0, qreal speed = 0, qreal initialOrientationDegrees = 0.0, QBrush const& brush = Qt::white, QDynamicEntity* parent = nullptr);
	~QRabbit() override = default;
	

	void advance(int phase) override;
	void statusChange() override;
	void seekFood() override;

	bool isPrey(QEntity const* entity) const override;

};




//class QDeer : public QDynamicEntities
//{
//
//
//
//};
