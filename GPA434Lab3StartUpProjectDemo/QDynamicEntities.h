//#pragma once
//
//#include "Qentities.h"
//
//
//class QDynamicEntities : public QEntities
//{
//
//	QList<QDynamicEntities> DynamicEntities;
//
//	QList<QRabbit*> mQRabbits;
//	QList<QWolf*> mQWolves;
//	QList<QDeer*> mQDeers;
//
//	// voir cest quoi la diff de qlits de parent ou q list de enfant
//
//	// dynamic cast 
//	
//
//
//public:
//
//	QDynamicEntities();
//
//	//Qt virtual function
//
//	virtual void seekFood(QList<QGraphicsItem*>& dynamicEntityInRange) = 0;						//cherche nourriture
//	virtual void pickWeakest(QList<QGraphicsItem*>& dynamicEntityInRange) = 0;					
//	virtual void pickNearest(QList<QGraphicsItem*>& dynamicEntityInRange) = 0;
//	virtual void mate(QList<QGraphicsItem*>& dynamicEntityInRange) = 0;
//	virtual void sameFamily(QList<QGraphicsItem*>& dynamicEntityInRange, bool sameFamily) = 0;
//	virtual void approach(QList<QGraphicsItem*>& dynamicEntityInRange) = 0;
//	virtual void consumeNutrient(QList<QGraphicsItem*>& dynamicEntityInRange) = 0;
//	virtual void wander(QList<QGraphicsItem*>& dynamicEntityInRange) = 0;
//
//
//private:
//	qreal const mMaxSpeed;
//	qreal mCurrentSpeed;
//
//	qreal const mMaxHealth;
//	qreal mCurrentHealth;
//
//	qreal const mMaxHunger;
//	qreal mCurrentHunger;
//
//	qreal const mAttackValue;
//
//	qreal const mMaxAge;
//	qreal mCurrentAge;
//	
//	bool mInHeat;
//
//};
//
//
//class QWolf : public QDynamicEntities
//{
//	//QWolf(qreal age = 1 , qreal hunger = 1 , qreal heat = 1, qreal speed = 1, QGraphicsItem *parent = nullptr);
//	//~QWolf() override = default;
//
//	//QArrowItem(double lifeExpectancy = 1.0, QPointF const& initialPosition = QPointF(), qreal initialOrientationDegrees = 0.0, qreal initialSpeed = 1.0, qreal scale = 1.0, QBrush const& brush = Qt::white, QGraphicsItem* parent = nullptr);
//
//	bool isAlive(QList<QGraphicsItem*>& predatorList) override;
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
//	void seekFood(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//	void pickWeakest(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//	void approach(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//	void mate(QList<QGraphicsItem*>& dynamicEntityInRange) override;
//	QPainterPath shape() override;
//	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;
//	QPainterPath opaqueArea() const override;
//
//
//
//
//
//
//
//
//};
//
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
