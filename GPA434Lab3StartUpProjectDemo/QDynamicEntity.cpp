#include "QDynamicEntity.h"

#include <QRandomGenerator>
#include <QtMath>
#include <cmath>

QDynamicEntity::QDynamicEntity(QPointF const& position, qreal age, qreal scale, qreal speed, qreal initialOrientationDegrees, QBrush const& brush, QEntity* parent)
	:QEntity(position, scale, brush, parent),
	mCurrentAge{age},	//tout les animaux vont etre initialise avec ces valeurs
	mMaxAge{100},
	mMaxHunger{30},
	mCurrentHunger{mMaxHunger},
	mCurrentSpeed{ speed },
	mMaxHealth{5},
	mCurrentHealth{mMaxHealth},
	mAttackValue{1},
	mInHeat{0},
	mNewOrientation{0}
{
	setRotation(initialOrientationDegrees);
}

bool QDynamicEntity::isAlive()
{

	if (mCurrentAge >= mMaxAge /* || mCurrentHunger <= 0*/ ) {

		return false;
	}

	return true;
	
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

void QDynamicEntity::entitiesInRange()
{
	mEntitiesInRange = scene()->items(mLineOfSight);
}

void QDynamicEntity::approach(QEntity* targetEntity)
{

	if (!targetEntity) return; // S'assurer que l'entité cible n'est pas nulle

	// Obtenir les positions actuelles
	QPointF currentPosition = pos();
	QPointF targetPosition = targetEntity->pos();

	// Calculer la direction vers l'entité cible
	QPointF direction = targetPosition - currentPosition;
	qreal distance = std::sqrt(direction.x() * direction.x() + direction.y() * direction.y());

	// Normaliser la direction
	direction /= distance;

	// Déterminer la nouvelle position selon la direction et la vitesse actuelle
	QPointF newPosition = currentPosition + direction * (2*mCurrentSpeed);

	// Si la nouvelle position est à l'extérieur de la scène, la téléporter à la région opposée de la scène
	warp(newPosition);

	// Appliquer la nouvelle position
	setPos(newPosition);

	// Ajuster l'orientation pour faire face à la cible
	qreal angle = std::atan2(-direction.y(), direction.x()) * 180 / M_PI;
	setRotation(angle);


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



void QDynamicEntity::sameFamily()
{

	for (QList<QGraphicsItem*>::iterator it = mEntitiesInRange.begin(); it != mEntitiesInRange.end();)
	{

		//QGraphicsItem item = it; //je dereference mon iterateur, et je le store dans un pointer de qgraphic item
		// quand jutilise item, je suis en train de modifier la memoire dans ma liste

		QEntity* entity = dynamic_cast<QEntity*>(*it);


		if (typeid(entity) != typeid(this)) {	//si pas du meme type
			it = mEntitiesInRange.erase(it); // vient deleter l'entite que je pointe dessus; vu que jai detruit mon iterateur en faisant ca
			// on reactualise le pointeur a it 
		}
		else 
		{
		++it;

		}
		
	}
}



void QDynamicEntity::filterPrey()	
{

	for (QList<QGraphicsItem*>::iterator it = mEntitiesInRange.begin(); it != mEntitiesInRange.end();)
	{

		QEntity* entity = dynamic_cast<QEntity*>(*it);


		if (entity && !isPrey(entity))
		{	

			it = mEntitiesInRange.erase(it); 

		}
		else
		{

		++it;
		}

	}

}




QEntity* QDynamicEntity::pickNearest()
{

	qreal nearestDistance= std::numeric_limits<qreal>::max();;
	QEntity* nearestEntity= nullptr;

	for (QList<QGraphicsItem*>::iterator it = mEntitiesInRange.begin(); it != mEntitiesInRange.end();)
	{
		QGraphicsItem* item = *it; //je dereference mon iterateur, et je le store dans un pointer de qgraphic item
		// quand jutilise item, je suis en train de modifier la memoire dans ma liste


		QEntity* entity = dynamic_cast<QEntity*>(item);

		if(entity && entity!=this){

			QLineF line(getEntityPosition(), entity->getEntityPosition());
			qreal distance = line.length();


			if (distance < nearestDistance) {

				nearestDistance = distance;
				nearestEntity = entity;
			}
		}
		++it;
	}
	return nearestEntity;
}



void QDynamicEntity::setAge(qreal age)
{
	mCurrentAge = age;
}

void QDynamicEntity::setHunger(qreal hunger)
{
	mCurrentHunger = hunger;
}

void QDynamicEntity::setSpeed(qreal speed)
{
	mCurrentSpeed = speed;
}

void QDynamicEntity::setHealth(qreal health)
{
	mCurrentHealth = health;
}

void QDynamicEntity::setHeat(bool heat)
{
	mInHeat = heat;
}


qreal QDynamicEntity::getAge() const
{
	return mCurrentAge;
}

qreal QDynamicEntity::getHunger() const
{
	return mCurrentHunger;
}

qreal QDynamicEntity::getSpeed() const
{
	return mCurrentSpeed;
}

qreal QDynamicEntity::getHealth() const
{
	return mCurrentHealth;
}

bool QDynamicEntity::getHeat() const
{
	return mInHeat;
}




/*****************************************Fonction Loup***********************************************************************/


QWolf::QWolf(QPointF const& position = QPointF(),qreal age, qreal scale, qreal speed, qreal initialOrientationDegrees, QBrush const& brush, QDynamicEntity* parent)
	:QDynamicEntity(position,age,scale,speed,initialOrientationDegrees,brush,parent)
{

	

	mLineOfSight.addEllipse(mPosition,250,250);
	mShape << QPointF(0, 0) << QPointF(1, 0) << QPointF(0.5, 1);	//affiche un petit triangle pour representer le loup

}

void QWolf::advance(int phase)
{
	if (mCurrentHunger < mMaxHunger/2)
	{

		filterPrey();

		seekFood();

	}
	wander(phase);
	mEntitiesInRange.clear(); //a changer de place
}

void QWolf::statusChange()
{
	mCurrentAge += 0.050;
	mCurrentHunger -= 0.1;


}

void QWolf::seekFood()
{
	entitiesInRange();
	approach(pickNearest());


}

bool QWolf::isPrey(QEntity const* entity) const
{
	return static_cast<bool>(dynamic_cast<const QRabbit*>(entity));
}


/**********************************************Fonctions Lapin*********************************************************************/

QRabbit::QRabbit(QPointF const& position = QPointF(), qreal age, qreal scale, qreal speed, qreal initialOrientationDegrees, QBrush const& brush, QDynamicEntity* parent)
	:QDynamicEntity(position, age, scale, speed, initialOrientationDegrees, brush, parent)
{
	

	mShape << QPointF(0, 0) << QPointF(1, 0) << QPointF(0.5, 1);	//affiche un petit triangle pour representer le loup

}

void QRabbit::advance(int phase)
{
	wander(phase);

	mEntitiesInRange.clear();	//a changer de place 
}


void QRabbit::statusChange()
{
	mCurrentAge += 0.030;

}

void QRabbit::seekFood()
{
}

bool QRabbit::isPrey(QEntity const* entity) const
{
	return static_cast<bool>(dynamic_cast<const QCarrot*>(entity));
	//return false;
}


