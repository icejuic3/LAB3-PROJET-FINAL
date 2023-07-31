#include "QEntities.h"

QEntities::QEntities(QPointF const& position,QGraphicsItem* parent)
:QGraphicsItem(parent)
	
,mFamilyId{"entity"}
,mQPen{Qt::black}
,mPosition{0,0}
,mColor{Qt::white}

{
	setPos(position);
}
