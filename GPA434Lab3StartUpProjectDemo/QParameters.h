#ifndef Q_PARAMETERS_H
#define Q_PARAMETERS_H


#include <QWidget>

class QSpinBox;


class QParameters : public QWidget
{
	Q_OBJECT

public:
	QParameters(size_t maxItems = 250, QWidget * parent = nullptr);

	size_t nbrOfItems() const; //a suprimer



	size_t nbrOfWolves() const;
	size_t nbrOfRabbits() const;
	size_t nbrOfDeers() const;
	size_t nbrOfCarrots() const;
	size_t nbrOfHerbs() const;

protected:
	QSpinBox * mNbrOfItems;	//a suprimer

	QSpinBox * mNbrOfWolves;
	QSpinBox * mNbrOfRabbits;
	QSpinBox * mNbrOfDeers;
	QSpinBox * mNbrOfCarrots;
	QSpinBox * mNbrOfHerbs;

};


#endif // Q_PARAMETERS_H