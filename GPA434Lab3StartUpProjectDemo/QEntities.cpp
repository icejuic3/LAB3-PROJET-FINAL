#include "QEntities.h"

QEntities::QEntities(QGraphicsItem* parent)
:QGraphicsItem(parent)
	
,mFamilyId{"entity"}
,mQPen{Qt::black}
,mQBrush{Qt::darkRed}
,mQEntityShape{}
,mPosition{0,0}
,mColor{Qt::white}

{
}
