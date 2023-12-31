#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GPA434Lab3StartUpProjectDemo.h"


#include <random>
#include <QGraphicsScene>
#include <QTimer>
#include "QDynamicEntity.h"
#include "QStaticEntity.h"


class QGraphicsView;
class QControlBar;
class QParameters;
class QPushButton;

	



class GPA434Lab3StartUpProjectDemo : public QMainWindow
{
    Q_OBJECT

public:
    GPA434Lab3StartUpProjectDemo(QWidget *parent = nullptr);
    ~GPA434Lab3StartUpProjectDemo();

	void addToSimulation(int choice, QEntity* entity);

private:
    Ui::GPA434Lab3StartUpProjectDemoClass ui;

	QGraphicsScene mGraphicsScene;
	QGraphicsView* mSimulationView;
	QParameters* mParameters;
	QControlBar* mControlBar;
	QPushButton* mAboutButton;
	QTimer mTimer;
	
	
	// Fonctions utilitaires de génération de valeurs aléatoires : devraient être ailleurs.
	double random(qreal maxValue);
	double random(qreal minValue, qreal maxValue);
	QColor randomColor();
	QPointF randomPoint(qreal min, qreal max);

private slots:
	void startSimulation();
	void stepSimulation();
	void pauseSimulation();
	void resumeSimulation();
	void stopSimulation();

	void advance();

	void about();

private:
	// Litéraux et variables symboliques utilisés
	static QSize	const sSceneSize;				// Taille de la scène
	static size_t	const sMaxNbrOfItems;			// Nombre maximum de flèche
	static QString	const sAboutButtonText;			// Text du bouton "À propos"
	static QString	const sAboutText;				// Text pour la boîte à propos
	static QString	const sControlStartText;		// Textes pour les contrôles
	static QString	const sControlStopText;			//    "
	static QString	const sControlPauseText;		//    "
	static QString	const sControlResumeText;		//    "
	static QString	const sControlStepText;			//    "
	static QColor	const sSceneBackgroundColor;	// Couleurs utilisées
	static QColor	const sControlRunningColor;		//    "
	static QColor	const sControlPauseColor;		//    "
	static QColor	const sControlStoppedColor;		//    "
	static QColor	const sControlNotReadyColor;	//    "
	//static qreal	const sCenterRadius;			//    "
	static qreal	const sMinOrientationDegrees;	//    "
	static qreal	const sMaxOrientationDegrees;	//    "
	static qreal	const sMinSpeed;				//    "
	static qreal	const sMaxSpeed;				//    "				
	static qreal	const sMinAge;
	static qreal	const sMaxAge;
	static qreal	const sMinHunger;
	static qreal	const sMaxHunger;
	static qreal	const sMinHeat;
	static qreal	const sMaxHeat;

	std::mt19937 mGen;
	std::uniform_int_distribution<> mDistrib;

};
