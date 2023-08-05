#pragma once

#include "QEntity.h"



class QDynamicEntity : public QEntity
{
public:	

	QDynamicEntity(QPointF const& position = QPointF(), qreal age=1.0, qreal hunger = 1.0, qreal heat=1.0, qreal scale = 1.0, qreal speed = 1.0, qreal initialOrientationDegrees = 0.0, QBrush const& brush = Qt::white, QEntity* parent = nullptr);
	~QDynamicEntity() override = default;


	//les fonctions que les animaux partagent en commun

	bool isAlive() override;
	static qreal warp(qreal value, qreal begin, qreal end);
	void warp(QPointF& point);
	QEntity* pickNearest(int status);					//retourne l'adresse de l'entite la plus proche?
	void approach(QEntity* targetEntity);					//se deplace vers l'entite la plus proche
	virtual void statusChange()=0;
	virtual bool isPrey(QEntity const * entity) const = 0;
	virtual bool isFamily(QEntity const * entity) const = 0;
	void advance(int phase) override;
	void wander(int phase);


protected:

	QDynamicEntity* targetAnimal;
	qreal mInHeat;
	qreal mHeatThreshold;
	qreal const mMaxAge;
	qreal mCurrentAge;
	qreal const mMaxHunger;
	qreal mCurrentHunger;
	qreal mCurrentSpeed;
	qreal const mMaxHealth;
	qreal mCurrentHealth;
	QPointF mNewPosition;
	qreal mNewOrientation;

};


class QWolf : public QDynamicEntity
{
	
public:

	QWolf(QPointF const& position, qreal age=1.0 , qreal hunger=1.0, qreal heat = 1.0, qreal scale = 1.0, qreal speed = 0, qreal initialOrientationDegrees = 0.0, QBrush const& brush = Qt::white, QDynamicEntity* parent = nullptr);
	~QWolf() override = default;

	void statusChange() override;
	bool isPrey(QEntity const* entity) const override;
	bool isFamily(QEntity const* entity) const override;

};

class QRabbit : public QDynamicEntity
{

public:

	QRabbit(QPointF const& position, qreal age = 1.0, qreal hunger = 1.0, qreal heat = 1.0, qreal scale = 1.0, qreal speed = 0, qreal initialOrientationDegrees = 0.0, QBrush const& brush = Qt::white, QDynamicEntity* parent = nullptr);
	~QRabbit() override = default;
	
	void statusChange() override;
	bool isPrey(QEntity const* entity) const override;
	bool isFamily(QEntity const* entity) const override;


};

class QDeer : public QDynamicEntity
{

public:

	QDeer(QPointF const& position, qreal age = 1.0, qreal hunger = 1.0, qreal heat = 1.0, qreal scale = 1.0, qreal speed = 0, qreal initialOrientationDegrees = 0.0, QBrush const& brush = Qt::white, QDynamicEntity* parent = nullptr);
	~QDeer() override = default;

	void statusChange() override;
	bool isPrey(QEntity const* entity) const override;
	bool isFamily(QEntity const* entity) const override;


};
