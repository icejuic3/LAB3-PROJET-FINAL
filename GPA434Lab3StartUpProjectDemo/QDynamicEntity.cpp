#include "QDynamicEntity.h"

#include <QRandomGenerator>
#include <QtMath>


QDynamicEntity::QDynamicEntity(QPointF const& position, qreal age, qreal scale, qreal speed, qreal initialOrientationDegrees, QBrush const& brush, QEntity* parent)
	:QEntity(position, scale, brush, parent),
	mCurrentAge{age},	//tout les animaux vont etre initialise avec ces valeurs
	mMaxAge{25},
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

	if (mCurrentAge >= mMaxAge || mCurrentHunger <= 0) {

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

void QDynamicEntity::dynamicEntitiesInRange()
{
	mEntitiesInRange = scene()->items(mLineOfSight);
}

void QDynamicEntity::approach()
{

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

		ageIncrement();
	}
}



void QDynamicEntity::sameFamily(bool sameFamily)
{
	for (auto it = mEntitiesInRange.begin(); it != mEntitiesInRange.end(); ++it) {
		QGraphicsItem* item = *it;

		QEntity* entity = dynamic_cast<QEntity*>(item);
		if (entity&& sameFamily) {
			if (entity->getFamilyId() == getFamilyId()) {
				//mEntitiesInRange.append(entity);
			}
			else if (entity && !sameFamily) {
				it = mEntitiesInRange.erase(it);
			}
			
		}
	}

}

void QDynamicEntity::pickNearest()
{

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

	mFamilyId = "wolf";

	mLineOfSight.addEllipse(mPosition,50,50);
	mShape << QPointF(0, 0) << QPointF(1, 0) << QPointF(0.5, 1);	//affiche un petit triangle pour representer le loup

}

void QWolf::advance(int phase)
{
	if (mCurrentHunger < mMaxHunger) {
		seekFood();
	}
	wander(phase);

}

void QWolf::ageIncrement()
{
	mCurrentAge += 0.050;
}

void QWolf::seekFood()
{
	dynamicEntitiesInRange();
	pickNearest();

}


/**********************************************Fonctions Lapin*********************************************************************/

QRabbit::QRabbit(QPointF const& position = QPointF(), qreal age, qreal scale, qreal speed, qreal initialOrientationDegrees, QBrush const& brush, QDynamicEntity* parent)
	:QDynamicEntity(position, age, scale, speed, initialOrientationDegrees, brush, parent)
{
	mFamilyId = "rabbit";

	mShape << QPointF(0, 0) << QPointF(1, 0) << QPointF(0.5, 1);	//affiche un petit triangle pour representer le loup

}

void QRabbit::advance(int phase)
{
	wander(phase);


}


void QRabbit::ageIncrement()
{
	mCurrentAge += 0.030;

}

void QRabbit::seekFood()
{
}
