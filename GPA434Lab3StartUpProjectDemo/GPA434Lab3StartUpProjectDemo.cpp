#include "GPA434Lab3StartUpProjectDemo.h"


#include <QRandomGenerator>
#include <QGraphicsView>
#include "QControlBar.h"
#include "QParameters.h"
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include "QArrowItem.h"


size_t	const GPA434Lab3StartUpProjectDemo::sMaxNbrOfItems{ 1000 };
QSize	const GPA434Lab3StartUpProjectDemo::sSceneSize(1000, 600);
QColor	const GPA434Lab3StartUpProjectDemo::sSceneBackgroundColor(QColor::fromHsl(215, 80, 222));
QString	const GPA434Lab3StartUpProjectDemo::sControlStartText("Démarrer la simulation");
QString	const GPA434Lab3StartUpProjectDemo::sControlStopText("Terminer la simulation");
QString	const GPA434Lab3StartUpProjectDemo::sControlPauseText("Mettre la simulation sur pause");
QString	const GPA434Lab3StartUpProjectDemo::sControlResumeText("Reprendre la simulation");
QString	const GPA434Lab3StartUpProjectDemo::sControlStepText("Faire un pas de simulation");
QColor	const GPA434Lab3StartUpProjectDemo::sControlRunningColor(0, 255, 0);
QColor	const GPA434Lab3StartUpProjectDemo::sControlPauseColor(255, 196, 0);
QColor	const GPA434Lab3StartUpProjectDemo::sControlStoppedColor(255, 0, 0);
QColor	const GPA434Lab3StartUpProjectDemo::sControlNotReadyColor(230, 230, 230);
qreal	const GPA434Lab3StartUpProjectDemo::sMinLifeExpectancy{ 1.0 };
qreal	const GPA434Lab3StartUpProjectDemo::sMaxLifeExpectancy{ 10.0 };
qreal	const GPA434Lab3StartUpProjectDemo::sCenterRadius{ 25 };
qreal	const GPA434Lab3StartUpProjectDemo::sMinOrientationDegrees{ 0.0 };
qreal	const GPA434Lab3StartUpProjectDemo::sMaxOrientationDegrees{ 360.0 };
qreal	const GPA434Lab3StartUpProjectDemo::sMinSpeed{ 1.0 };
qreal	const GPA434Lab3StartUpProjectDemo::sMaxSpeed{ 5.0 };
qreal	const GPA434Lab3StartUpProjectDemo::sMinSize{ 7.5 };
qreal	const GPA434Lab3StartUpProjectDemo::sMaxSize{ 15.0 };

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
		QArrowItem* arrow{ dynamic_cast<QArrowItem*>(item) };
		if (arrow && !arrow->isAlive()) {
			mGraphicsScene.removeItem(arrow);
			delete arrow;
		}
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

	// Ajoute les n flèches
	for (int i{ 0 }; i < mParameters->nbrOfItems(); ++i) {
		mGraphicsScene.addItem(
			new QArrowItem(random(sMinLifeExpectancy, sMaxLifeExpectancy),	// espérance de vie en seconde
				randomPoint(-sCenterRadius, sCenterRadius),					// ils sont tous près de l'origine au départ!
				random(sMinOrientationDegrees, sMaxOrientationDegrees),		// orientation aléatoire
				random(sMinSpeed, sMaxSpeed),								// vitesse aléatoire
				random(sMinSize, sMaxSize),									// taille aléatoire
				randomColor()));											// couleur aléatoire
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
	QMessageBox::about(this, "À propos...", sAboutText);
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

QPointF GPA434Lab3StartUpProjectDemo::randomPoint(qreal min, qreal max)
{
	return QPointF(random(min, max), random(min, max));
}

