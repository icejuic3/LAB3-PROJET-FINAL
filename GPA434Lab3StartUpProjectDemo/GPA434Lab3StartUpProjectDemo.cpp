#include "GPA434Lab3StartUpProjectDemo.h"


#include <QRandomGenerator>
#include <QGraphicsView>
#include "QControlBar.h"
#include "QParameters.h"
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include "QArrowItem.h"
#include <QGraphicsRectItem>


/****************NOS INCLUDES (A REVOIR)******************/



/*********************************/


size_t	const GPA434Lab3StartUpProjectDemo::sMaxNbrOfItems{ 1000 };
QSize	const GPA434Lab3StartUpProjectDemo::sSceneSize(1000, 600);
QColor	const GPA434Lab3StartUpProjectDemo::sSceneBackgroundColor(QColor(240,240,240));
QString	const GPA434Lab3StartUpProjectDemo::sControlStartText("Démarrer la simulation");
QString	const GPA434Lab3StartUpProjectDemo::sControlStopText("Terminer la simulation");
QString	const GPA434Lab3StartUpProjectDemo::sControlPauseText("Mettre la simulation sur pause");
QString	const GPA434Lab3StartUpProjectDemo::sControlResumeText("Reprendre la simulation");
QString	const GPA434Lab3StartUpProjectDemo::sControlStepText("Faire un pas de simulation");
QColor	const GPA434Lab3StartUpProjectDemo::sControlRunningColor(0, 255, 0);
QColor	const GPA434Lab3StartUpProjectDemo::sControlPauseColor(255, 196, 0);
QColor	const GPA434Lab3StartUpProjectDemo::sControlStoppedColor(255, 0, 0);
QColor	const GPA434Lab3StartUpProjectDemo::sControlNotReadyColor(230, 230, 230);
//qreal	const GPA434Lab3StartUpProjectDemo::sCenterRadius{ 25 };


qreal	const GPA434Lab3StartUpProjectDemo::sMinOrientationDegrees{ 0.0 };
qreal	const GPA434Lab3StartUpProjectDemo::sMaxOrientationDegrees{ 360.0 };

qreal	const GPA434Lab3StartUpProjectDemo::sMinHunger{ 15.0 };
qreal	const GPA434Lab3StartUpProjectDemo::sMaxHunger{ 50.0 };

qreal	const GPA434Lab3StartUpProjectDemo::sMinHeat{ 0.0 };
qreal	const GPA434Lab3StartUpProjectDemo::sMaxHeat{ 30.0 };

qreal	const GPA434Lab3StartUpProjectDemo::sMinSpeed{ 1.0 };
qreal	const GPA434Lab3StartUpProjectDemo::sMaxSpeed{ 5.0 };

qreal	const GPA434Lab3StartUpProjectDemo::sMinAge{ 1.0 };
qreal	const GPA434Lab3StartUpProjectDemo::sMaxAge{ 50.0 };




const QString GPA434Lab3StartUpProjectDemo::sAboutButtonText("À propos...");
const QString GPA434Lab3StartUpProjectDemo::sAboutText(
    R"..(GPA434 
Ingénierie des systèmes orientés objets

Laboratoire  3
Simulation d'un écosystème 

Ce projet consiste à ...

Réalisé par :
   - Étudiant 1
   - Étudiant 2
   - ...
)..");



GPA434Lab3StartUpProjectDemo::GPA434Lab3StartUpProjectDemo(QWidget *parent)
    : QMainWindow(parent)
	, mSimulationView{ new QGraphicsView(&mGraphicsScene) }
	, mParameters{ new QParameters(sMaxNbrOfItems) }
	, mControlBar{ new QControlBar(Qt::Vertical) }
	, mAboutButton{ new QPushButton(sAboutButtonText) }
	, mGen(std::random_device{}())
	, mDistrib{ 0,2 }
	

{
	setWindowTitle("Startup project demo");
	setWindowIcon(QIcon(":/StartUpProjectDemo/icon"));

	ui.setupUi(this);

	mControlBar->setReady();
	mControlBar->setActionText(QControlBar::Action::Start, sControlStartText);
	mControlBar->setActionText(QControlBar::Action::Stop, sControlStopText);
	mControlBar->setActionText(QControlBar::Action::Pause, sControlPauseText);
	mControlBar->setActionText(QControlBar::Action::Resume, sControlResumeText);
	mControlBar->setActionText(QControlBar::Action::Step, sControlStepText);
	mControlBar->setStateColor(QControlBar::State::NotReady, sControlNotReadyColor);
	mControlBar->setStateColor(QControlBar::State::Paused, sControlPauseColor);
	mControlBar->setStateColor(QControlBar::State::Running, sControlRunningColor);
	mControlBar->setStateColor(QControlBar::State::Stopped, sControlStoppedColor);

	mGraphicsScene.setSceneRect(-sSceneSize.width() / 2, -sSceneSize.height() / 2, sSceneSize.width(), sSceneSize.height());



	QWidget* controlWidget{ new QWidget };
	QVBoxLayout* controlLayout{ new QVBoxLayout };

	controlWidget->setLayout(controlLayout);
	controlLayout->addWidget(mParameters);
	controlLayout->addStretch();
	controlLayout->addWidget(mControlBar);
	controlLayout->addWidget(mAboutButton);

	QWidget* centralWidget{ new QWidget };
	QHBoxLayout* centralLayout{ new QHBoxLayout };
	centralWidget->setLayout(centralLayout);

	centralLayout->addWidget(mSimulationView);
	centralLayout->addWidget(controlWidget);

	

	setCentralWidget(centralWidget);

	connect(mControlBar, &QControlBar::started, this, &GPA434Lab3StartUpProjectDemo::startSimulation);
	connect(mControlBar, &QControlBar::stopped, this, &GPA434Lab3StartUpProjectDemo::stopSimulation);
	connect(mControlBar, &QControlBar::paused, this, &GPA434Lab3StartUpProjectDemo::pauseSimulation);
	connect(mControlBar, &QControlBar::resumed, this, &GPA434Lab3StartUpProjectDemo::resumeSimulation);
	connect(mControlBar, &QControlBar::stepped, this, &GPA434Lab3StartUpProjectDemo::stepSimulation);



	connect(&mTimer, &QTimer::timeout, this, &GPA434Lab3StartUpProjectDemo::advance);

	connect(mAboutButton, &QPushButton::clicked, this, &GPA434Lab3StartUpProjectDemo::about);
}


GPA434Lab3StartUpProjectDemo::~GPA434Lab3StartUpProjectDemo()
{}



void GPA434Lab3StartUpProjectDemo::advance()
{
	mGraphicsScene.advance();


	for (auto& item : mGraphicsScene.items()) {

		QEntity* entity{ dynamic_cast<QEntity*>(item) };

		if (entity && !entity->isAlive())
		{
			int choices[] = { 4, 5 };
			int choiceIndex = mDistrib(mGen);
			int choice = choices[choiceIndex];

			mGraphicsScene.removeItem(entity);

			if (dynamic_cast<QWolf*>(entity)) {

				addToSimulation(choice, entity);
			}
			else if (dynamic_cast<QRabbit*>(entity)) {

				addToSimulation(choice, entity);
			}
			else if (dynamic_cast<QDeer*>(entity)) {

				addToSimulation(choice, entity);
			}
			delete entity;
		}
		else if(entity && entity->isBorn())
		{
			if (dynamic_cast<QWolf*>(entity)) {

				addToSimulation(1, entity);

			}
			else if (dynamic_cast<QRabbit*>(entity)) {

				addToSimulation(2, entity);
			}
			else if (dynamic_cast<QDeer*>(entity)) {

				addToSimulation(3, entity);
			}
		}
	}
}



void GPA434Lab3StartUpProjectDemo::addToSimulation(int choice, QEntity* entity)
{
	
	switch (choice) {

	case 1:

		mGraphicsScene.addItem(
			new QWolf(entity->pos()						//position de depart
				, random(sMinAge, sMaxAge)													//age random
				, random(sMinHunger, sMaxHunger)
				, random(sMinHeat, sMaxHeat)
				, 15																		//taille du loup
				, 1.0																		//vitess du loup	
				, random(sMinOrientationDegrees, sMaxOrientationDegrees)					//orientation
				, QColor(Qt::black))														//couleur
		);
		break;

	case 2:

		mGraphicsScene.addItem(
			new QRabbit(entity->pos() //position de depart
				, random(sMinAge, sMaxAge)													 //age random
				, random(sMinHunger, sMaxHunger)
				, random(sMinHeat, sMaxHeat)
				, 10																			 //taille du lapin
				, 1.3																		 //vitess du lapin	
				, random(sMinOrientationDegrees, sMaxOrientationDegrees)					 //orientation
				, QColor(Qt::lightGray))													 //couleur
		);
		break;

	case 3:

		mGraphicsScene.addItem(
			new QDeer(entity->pos()
				, random(sMinAge, sMaxAge)
				, random(sMinHunger, sMaxHunger)
				, random(sMinHeat, sMaxHeat)
				, 13
				, 1.2
				, random(sMinOrientationDegrees, sMaxOrientationDegrees)
				, QColor(Qt::cyan))
		);
		break;

	case 4:


		mGraphicsScene.addItem(
			new QCarrot(entity->pos()
				, 7																				
				, QColor(Qt::yellow))
		);
		break;

	case 5:

		mGraphicsScene.addItem(
			new QHerb(entity->pos()			//position de depart
				, 10																				//taille herbe
				, QColor(Qt::green))
		);
		break;


	default:
		break;
	}
}

void GPA434Lab3StartUpProjectDemo::startSimulation()
{
	// Vide la scène pour démarrer une nouvelle démo
	mGraphicsScene.clear();

	// Met un item rectangulaire pour bien voir les limites de la scène
	QGraphicsRectItem* background{ new QGraphicsRectItem(mGraphicsScene.sceneRect()) };
	background->setPen(Qt::NoPen);
	background->setBrush(sSceneBackgroundColor);
	mGraphicsScene.addItem(background);


	// ajoute n Loup
	for (int i{ 0 }; i < mParameters->nbrOfWolves(); ++i)
	{
		mGraphicsScene.addItem(
			new QWolf(randomPoint(mGraphicsScene.width() / 2, mGraphicsScene.height() / 2)	//position de depart
				, random(sMinAge, sMaxAge)													//age random
				, random(sMinHunger, sMaxHunger)
				, random(sMinHeat, sMaxHeat)
				, 15																		//taille du loup
				, 1.0																		//vitess du loup	
				, random(sMinOrientationDegrees, sMaxOrientationDegrees)					//orientation
				, QColor(Qt::black)));
	}

	//ajoute n lapins
	for (int j{ 0 }; j < mParameters->nbrOfRabbits(); ++j)
	{
		mGraphicsScene.addItem(
			new QRabbit(randomPoint(mGraphicsScene.width() / 2, mGraphicsScene.height() / 2) //position de depart
				, random(sMinAge, sMaxAge)													 //age random
				, random(sMinHunger, sMaxHunger)
				, random(sMinHeat, sMaxHeat)
				, 10																		 //taille du lapin
				, 1.3																			 //vitess du lapin	
				, random(sMinOrientationDegrees, sMaxOrientationDegrees)					 //orientation
				, QColor(Qt::lightGray))
			);
	}

	//ajoute n chevereuils
	for (int k{ 0 }; k < mParameters->nbrOfDeers(); ++k)
	{
		mGraphicsScene.addItem(
			new QDeer(randomPoint(mGraphicsScene.width() / 2, mGraphicsScene.height() / 2)
				, random(sMinAge, sMaxAge)													 
				, random(sMinHunger, sMaxHunger)
				, random(sMinHeat, sMaxHeat)
				, 13																			
				, 1.2																		 
				, random(sMinOrientationDegrees, sMaxOrientationDegrees)					 
				, QColor(Qt::cyan))
		);
	}

	//ajoute n carrotes
	for (int l{ 0 }; l < mParameters->nbrOfCarrots(); ++l)
	{
		mGraphicsScene.addItem(
			new QCarrot(randomPoint(mGraphicsScene.width() / 2, mGraphicsScene.height() / 2)
				, 7
				, QColor(Qt::yellow))
		);
	}

	//ajoutes n herbes
	for (int m{ 0 }; m < mParameters->nbrOfHerbs(); ++m)
	{
		mGraphicsScene.addItem(
			new QHerb(randomPoint(mGraphicsScene.width()/2, mGraphicsScene.height()/2)		//position de depart
				, 10																		//taille herbe
				, QColor(Qt::green))
		);
	}
	
	// Démarre la simulation
	mTimer.start(30);
	mParameters->setEnabled(false);
}

void GPA434Lab3StartUpProjectDemo::stepSimulation()
{
	mGraphicsScene.advance();
}

void GPA434Lab3StartUpProjectDemo::pauseSimulation()
{
	mTimer.stop();
}

void GPA434Lab3StartUpProjectDemo::resumeSimulation()
{
	mTimer.start(30);
}

void GPA434Lab3StartUpProjectDemo::stopSimulation()
{
	mTimer.stop();
	mParameters->setEnabled(true);
}

void GPA434Lab3StartUpProjectDemo::about()
{
	QMessageBox::about(this, "In this simulation ", sAboutText);
}


double GPA434Lab3StartUpProjectDemo::random(qreal maxValue)
{
	return QRandomGenerator::global()->bounded(maxValue);
}

double GPA434Lab3StartUpProjectDemo::random(qreal minValue, qreal maxValue)
{
	return random(maxValue - minValue) + minValue;
}

QColor GPA434Lab3StartUpProjectDemo::randomColor()
{
	return QColor::fromRgb(QRandomGenerator::global()->generate());
}


QPointF GPA434Lab3StartUpProjectDemo::randomPoint(qreal width, qreal height)
{

	return QPointF(random(-width/2, width), random(-height/2, height));
}

