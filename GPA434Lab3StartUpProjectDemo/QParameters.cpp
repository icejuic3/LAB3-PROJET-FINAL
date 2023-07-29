#include "QParameters.h"


#include <QSpinBox>
#include <QFormLayout>
#include <QtMath>


QParameters::QParameters(size_t maxItems, QWidget * parent)
	:	QWidget(parent),
		mNbrOfItems{ new QSpinBox },	//a suprimer

	    mNbrOfWolves{new QSpinBox},
	    mNbrOfRabbits{new QSpinBox},
	    mNbrOfDeers{ new QSpinBox },
	    mNbrOfCarrots{ new QSpinBox },
	    mNbrOfHerbs{ new QSpinBox }


{
	const size_t minMaxNbr{ 10 };

	mNbrOfItems->setRange(1, qMax(static_cast<size_t>(minMaxNbr), maxItems));// a suprimer
	mNbrOfItems->setValue(minMaxNbr);// a suprimer

	mNbrOfWolves->setRange(1, qMax(static_cast<size_t>(minMaxNbr), maxItems));
	mNbrOfWolves->setValue(minMaxNbr);

	mNbrOfRabbits->setRange(1, qMax(static_cast<size_t>(minMaxNbr), maxItems));
	mNbrOfRabbits->setValue(minMaxNbr);

	mNbrOfDeers->setRange(1, qMax(static_cast<size_t>(minMaxNbr), maxItems));
	mNbrOfDeers->setValue(minMaxNbr);

	mNbrOfCarrots->setRange(1, qMax(static_cast<size_t>(minMaxNbr), maxItems));
	mNbrOfCarrots->setValue(minMaxNbr);

	mNbrOfHerbs->setRange(1, qMax(static_cast<size_t>(minMaxNbr), maxItems));
	mNbrOfHerbs->setValue(minMaxNbr);


	QFormLayout * layout{ new QFormLayout };
	layout->addRow("Nombre d'items ", mNbrOfItems);	// a suprimer

	layout->addRow("Nombre de loups ", mNbrOfWolves);
	layout->addRow("Nombre de lapins ", mNbrOfRabbits);
	layout->addRow("Nombre de chevreuils ", mNbrOfDeers);
	layout->addRow("Nombre de carrottes ", mNbrOfCarrots);
	layout->addRow("Nombre d'herbes ", mNbrOfHerbs);
	
	setLayout(layout);

}

size_t QParameters::nbrOfItems() const	// a suprimer
{
	return static_cast<size_t>(mNbrOfItems->value());
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




