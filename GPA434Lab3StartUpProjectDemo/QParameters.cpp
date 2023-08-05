#include "QParameters.h"


#include <QSpinBox>
#include <QFormLayout>
#include <QtMath>


QParameters::QParameters(size_t maxItems, QWidget * parent)
	:	QWidget(parent),
		

	    mNbrOfWolves{new QSpinBox},
	    mNbrOfRabbits{new QSpinBox},
	    mNbrOfDeers{ new QSpinBox },
	    mNbrOfCarrots{ new QSpinBox },
	    mNbrOfHerbs{ new QSpinBox }


{
	const size_t minMaxNbr{ 2 };


	mNbrOfWolves->setRange(0, qMax(static_cast<size_t>(minMaxNbr), maxItems));
	mNbrOfWolves->setValue(4);

	mNbrOfRabbits->setRange(0, qMax(static_cast<size_t>(minMaxNbr), maxItems));
	mNbrOfRabbits->setValue(10);

	mNbrOfDeers->setRange(0, qMax(static_cast<size_t>(minMaxNbr), maxItems));
	mNbrOfDeers->setValue(6);

	mNbrOfCarrots->setRange(0, qMax(static_cast<size_t>(minMaxNbr), maxItems));
	mNbrOfCarrots->setValue(30);

	mNbrOfHerbs->setRange(0, qMax(static_cast<size_t>(minMaxNbr), maxItems));
	mNbrOfHerbs->setValue(30);


	QFormLayout * layout{ new QFormLayout };

	layout->addRow("Nombre de loups ", mNbrOfWolves);
	layout->addRow("Nombre de lapins ", mNbrOfRabbits);
	layout->addRow("Nombre de chevreuils ", mNbrOfDeers);
	layout->addRow("Nombre de carrottes ", mNbrOfCarrots);
	layout->addRow("Nombre d'herbes ", mNbrOfHerbs);
	
	setLayout(layout);

}

size_t QParameters::nbrOfWolves() const
{
	return static_cast<size_t>(mNbrOfWolves->value());
}

size_t QParameters::nbrOfRabbits() const
{
	return static_cast<size_t>(mNbrOfRabbits->value());
}

size_t QParameters::nbrOfDeers() const
{
	return static_cast<size_t>(mNbrOfDeers->value());
}

size_t QParameters::nbrOfCarrots() const
{
	return static_cast<size_t>(mNbrOfCarrots->value());
}

size_t QParameters::nbrOfHerbs() const
{
	return static_cast<size_t>(mNbrOfHerbs->value());
}




