#include "QDynamicEntity.h"

#include <QRandomGenerator>
#include <QtMath>
#include <cmath>
#include <typeinfo>
#include <string.h>
#include "QStaticEntity.h"


QDynamicEntity::QDynamicEntity(QPointF const& position, qreal age, qreal hunger, qreal heat, qreal scale, qreal speed, qreal initialOrientationDegrees, QBrush const& brush, QEntity* parent)
	:QEntity(position, scale, brush, parent),
	mCurrentAge{age},	//tout les animaux vont etre initialise avec ces valeurs
	mMaxAge{80},
	mMaxHunger{75},
	mCurrentHunger{hunger},
	mCurrentSpeed{ speed },
	mMaxHealth{5},
	mCurrentHealth{mMaxHealth},
	mInHeat{ heat },
	mHeatThreshold{50},
	mNewOrientation{0},
	targetAnimal{nullptr}

{
	setRotation(initialOrientationDegrees);
}

bool QDynamicEntity::isAlive()
{
	if (mAlive)
	{
		if (mCurrentAge >= mMaxAge || mCurrentHunger <= 0) {

			mAlive = 0;
			return mAlive;
		}
		return mAlive;
	}
	else{

		return mAlive;
	}
}

void QDynamicEntity::wander(int phase)
{
	if (phase == 0) {
		static qreal const maxDeltaOrientation{ 12.5 }; // in °
		// Détermine la nouvelle orientation selon une variation aléatoire dans l'intervalle [-maxDeltaOrientation, maxDeltaOrientation] => ± 12.5°

		mNewOrientation = rotation() + QRandomGenerator::global()->bounded(2.0 * maxDeltaOrientation) - maxDeltaOrientation;
		// Détermine la nouvelle position selon la nouvelle orientation et la vitesse

		qreal newOrientationRadians{ qDegreesToRadians(mNewOrientation) };
		mNewPosition = pos() + QPointF(qCos(newOrientationRadians), qSin(newOrientationRadians)) * mCurrentSpeed;
		// Si la nouvelle position est à l'extérieur de la scène, la nouvelle position est téléportée à la région opposée de la scène
		warp(mNewPosition);
		//
		// Applique le comportement
	}
	else if (phase == 1) {
		// Applique la nouvelle orientation et la nouvelle position
		setRotation(mNewOrientation);
		setPos(mNewPosition);

		// Plus vieux... le temps fil si rapidement...

		statusChange();
	}

}

qreal QDynamicEntity::warp(qreal value, qreal begin, qreal end)
{
	qreal const width = end - begin;
	return value - qFloor((value - begin) / width) * width;
}

void QDynamicEntity::warp(QPointF& point)
{
	point.setX(warp(point.x(), scene()->sceneRect().left(), scene()->sceneRect().right()));
	point.setY(warp(point.y(), scene()->sceneRect().top(), scene()->sceneRect().bottom()));
}

QEntity* QDynamicEntity::pickNearest(int status)
{

	qreal nearestDistance = std::numeric_limits<qreal>::max();
	QEntity* nearestEntity{ nullptr };

	for (auto& item : scene()->items())
	{

		QEntity* entity{ dynamic_cast<QEntity*>(item) };


		if (entity && entity != this && isPrey(entity) && status == 1)
		{
			QLineF line(pos(), entity->pos());
			qreal distance = line.length();

			if (distance < nearestDistance)
			{

				nearestDistance = distance;
				nearestEntity = entity;
			}

		}

		//&& typeid(entity) == typeid(this)
		else if (entity && entity != this && isFamily(entity) && status == 2)
		{
			QLineF line(pos(), entity->pos());
			qreal distance = line.length();

			if (distance < nearestDistance)
			{

				nearestDistance = distance;
				nearestEntity = entity;
			}
		}
	}

	return nearestEntity;
}

void QDynamicEntity::approach(QEntity* targetEntity)
{

	if (!targetEntity) {
		return; // S'assurer que l'entité cible n'est pas nulle
	}
		
	// Obtenir les positions actuelles
	QPointF currentPosition = pos();
	QPointF targetPosition = targetEntity->pos();

	// Calculer la direction vers l'entité cible
	QPointF direction = targetPosition - currentPosition;
	qreal distance = std::sqrt(direction.x() * direction.x() + direction.y() * direction.y());

	// Normaliser la direction
	direction /= distance;

	// Déterminer la nouvelle position selon la direction et la vitesse actuelle
	QPointF newPosition = currentPosition + direction * (3*mCurrentSpeed);

	// Si la nouvelle position est à l'extérieur de la scène, la téléporter à la région opposée de la scène
	warp(newPosition);

	// Appliquer la nouvelle position
	setPos(newPosition);

	// Ajuster l'orientation pour faire face à la cible
	qreal angle = std::atan2(-direction.y(), direction.x()) * 180 / M_PI;
	setRotation(angle);
}

void QDynamicEntity::advance(int phase)
{
	mBorn = 0;

	if (phase == 0)
	{

		if (mCurrentHunger <= mMaxHunger / 2)
		{
			status = 1;
			targetEntity = pickNearest(status);	//retourne la proie la plus proche

			if (!targetEntity) {
				wander(phase);
			}
		}
		else if (mInHeat >=mHeatThreshold)
		{
			status = 2;
			targetEntity = pickNearest(status);	//retourne le membre de famille le plus proche

			if (!targetEntity) {
				wander(phase);
			}
		}
		else
		{
			status = 0; 

			wander(phase);

		}
	}
	else if (phase == 1)
	{

		if (status != 0 && targetEntity)
		{

			approach(targetEntity);
			
			for (auto item : collidingItems())
			{
				QEntity* ptr{ dynamic_cast<QEntity*>(item) };
				QDynamicEntity* animal{ (dynamic_cast<QDynamicEntity*>(item)) };

				if (ptr && isPrey(ptr) && status == 1)
				{

					ptr->mAlive = false;
					mCurrentHunger = mMaxHunger;

				}
				else if (animal && isFamily(animal) && status == 2)
				{
					mInHeat = 0;
					mBorn = 1;
					animal->mInHeat = 0;
					isBorn();
				}
			}
		}
		else	
		{
			wander(phase);
		}
		// Plus vieux... le temps fil si rapidement...
		statusChange();
	}
}




/*****************************************Fonction Loup***********************************************************************/


QWolf::QWolf(QPointF const& position = QPointF(), qreal age, qreal hunger, qreal heat, qreal scale, qreal speed, qreal initialOrientationDegrees, QBrush const& brush, QDynamicEntity* parent)
	:QDynamicEntity(position,age,hunger,heat,scale,speed,initialOrientationDegrees,brush,parent)
{
	mShape << QPointF(0, 0) << QPointF(1, 0) << QPointF(0.5, 1);	//affiche un petit triangle pour representer le loup
}



void QWolf::statusChange()
{
	mCurrentAge += 0.050;
	mCurrentHunger -= 0.09;
	mInHeat += 0.08;
}


bool QWolf::isPrey(QEntity const* entity) const
{
	return static_cast<bool>(dynamic_cast<const QRabbit*>(entity)) || static_cast<bool>(dynamic_cast<const QDeer*>(entity));
}

bool QWolf::isFamily(QEntity const* entity) const
{
	return static_cast<bool>(dynamic_cast<const QWolf*>(entity));
}


/**********************************************Fonctions Lapin*********************************************************************/

QRabbit::QRabbit(QPointF const& position = QPointF(), qreal age, qreal hunger, qreal heat, qreal scale, qreal speed, qreal initialOrientationDegrees, QBrush const& brush, QDynamicEntity* parent)
	:QDynamicEntity(position, age, hunger,heat, scale, speed, initialOrientationDegrees, brush, parent)
{
	mShape << QPointF(0, 0) << QPointF(1, 0) << QPointF(0.5, 1);	//affiche un petit triangle pour representer le lapin
}


void QRabbit::statusChange()
{
	mCurrentAge += 0.035;
	mCurrentHunger -= 0.05;
	mInHeat += 0.15;
}



bool QRabbit::isPrey(QEntity const* entity) const
{
	return static_cast<bool>(dynamic_cast<const QCarrot*>(entity));
}

bool QRabbit::isFamily(QEntity const* entity) const
{
	return static_cast<bool>(dynamic_cast<const QRabbit*>(entity));
}

/*****************************************Fonction Deer***********************************************************************/


QDeer::QDeer(QPointF const& position = QPointF(), qreal age, qreal hunger, qreal heat, qreal scale, qreal speed, qreal initialOrientationDegrees, QBrush const& brush, QDynamicEntity* parent)
	:QDynamicEntity(position, age, hunger, heat, scale, speed, initialOrientationDegrees, brush, parent)
{
	mShape << QPointF(0, 0) << QPointF(1, 0) << QPointF(0.5, 1);	//affiche un petit triangle pour representer le lapin
}


void QDeer::statusChange()
{
	mCurrentAge += 0.040;
	mCurrentHunger -= 0.075;
	mInHeat += 0.1;
}


bool QDeer::isPrey(QEntity const* entity) const
{
	return static_cast<bool>(dynamic_cast<const QHerb*>(entity));
}

bool QDeer::isFamily(QEntity const* entity) const
{
	return static_cast<bool>(dynamic_cast<const QDeer*>(entity));
}











/***************************CODE QU'ON N'UTILISE PLUS*********************************************/


//void QDynamicEntity::entitiesInRange()
//{
//	mEntitiesInRange.clear();
//
//	QList<QGraphicsItem*> itemsInLineOfSight = scene()->items(mLineOfSight);
//
//	for (QGraphicsItem* item : itemsInLineOfSight)
//	{
//		if (item != this)
//		{										// Si l'élément n'est pas l'entité elle-même
//			mEntitiesInRange.append(item);		// Ajoute à la liste
//		}
//	}
//
//	//mEntitiesInRange = scene()->items(mLineOfSight);
//
//}


//void QDynamicEntity::sameFamily()
//{
//
//	for (QList<QGraphicsItem*>::iterator it = mEntitiesInRange.begin(); it != mEntitiesInRange.end();)
//	{
//
//		//QGraphicsItem item = it; //je dereference mon iterateur, et je le store dans un pointer de qgraphic item
//		// quand jutilise item, je suis en train de modifier la memoire dans ma liste
//
//		QEntity* entity = dynamic_cast<QEntity*>(*it);
//
//
//		if (typeid(entity) != typeid(this)) {	//compare une entite par le type(seulement si elles sont de meme type)
//
//			it = mEntitiesInRange.erase(it); // vient deleter l'entite que je pointe dessus; vu que jai detruit mon iterateur en faisant ca
//			// on reactualise le pointeur a it 
//		}
//		else if (std::string(typeid(*entity).name()) != (std::string(typeid(*this).name()))){ //compare une entite par le nom du type donc on peut comparer des entite de type different
//
//
//
//		}
//		++it;
//	}
//}


//void QDynamicEntity::filterPrey()	
//{
//
//	for (QList<QGraphicsItem*>::iterator it = mEntitiesInRange.begin(); it != mEntitiesInRange.end();)
//	{
//
//		QEntity* entity = dynamic_cast<QEntity*>(*it);
//
//		if (entity && !isPrey(entity))	//
//		{	
//			it = mEntitiesInRange.erase(it); 
//		}
//		else
//		{
//		++it;
//		}
//	}
//}

//QEntity* QDynamicEntity::entityDetected()
//{
//
//	//for (QGraphicsItem* item : mEntitiesInRange)
//	for (auto& item : scene()->items())
//	{
//		QEntity* entity = dynamic_cast<QEntity*>(item);
//
//		// Vérifier si l'entité n'est pas nulle et si elle n'est pas le loup lui-même
//		if (entity && entity != this)
//		{
//			// Vérifier si le loup entre en collision avec l'entité (par exemple, un lapin)
//			if (collidesWithItem(entity))
//			{
//				return entity; // Collision détectée, retourner l'entité
//			}
//		}
//	}
//	return nullptr; // Aucune collision détectée
//
//}

//void QDynamicEntity::seekFood()
//{
//	
//
//	//QEntity* detectedEntity = entityDetected();
//	//
//	//if (detectedEntity && isPrey(detectedEntity)) //si l'entite detecte une colision
//	//{
//	//	detectedEntity->mAlive = false;
//	//
//	//	mCurrentHunger = mMaxHunger;
//	//}
//	//
//}

