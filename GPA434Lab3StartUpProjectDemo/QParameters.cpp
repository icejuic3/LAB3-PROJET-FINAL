#include "QParameters.h"


#include <QSpinBox>
#include <QFormLayout>
#include <QtMath>


QParameters::QParameters(size_t maxItems, QWidget * parent)
	:	QWidget(parent),
		mNbrOfItems{ new QSpinBox }





{
	const size_t minMaxNbr{ 10 };

	mNbrOfItems->setRange(1, qMax(static_cast<size_t>(minMaxNbr), maxItems));
	mNbrOfItems->setValue(minMaxNbr);

	QFormLayout * layout{ new QFormLayout };
	layout->addRow("Nombre d'items ", mNbrOfItems);
	
	setLayout(layout);
}

size_t QParameters::nbrOfItems() const
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




