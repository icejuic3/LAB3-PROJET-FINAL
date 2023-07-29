//#include "QStaticEntities.h"
//
//
//
//
//QStaticEntities::QStaticEntities(QEntities* parent)
//:QEntities(parent)
//,mHerbs{}
//,mCarrots{}
//,mBodies{}
//,mFeces{}
//,mMaxFoodValue{}
//,mCurrentFoodValue{}
//,mGrowingSpeed{}
//,mCurrentMaturationStage{}
//,mReadyToEat{}
//,mIsEdible{}
//,mGrows{}
//{
//}
//
//
//
//QHerb::QHerb(QPointF const& initialPosition, qreal scale, QBrush const& brush, QStaticEntities* parent)
//	:	QStaticEntities(parent),
//		mBrush(brush)
//{
//	mShape << QPointF(0, 0) << QPointF(1, 0) << QPointF(1, 1) << QPointF(0, 1);	//affiche un petit carre pour representer l'herbe
//
//	setPos(initialPosition);
//	setScale(scale);
//
//
//}
//
//void QHerb::setColor(QBrush const& brush)
//{
//	mBrush = brush;
//}
//
//QRectF QHerb::boundingRect() const
//{
//	return mShape.boundingRect();
//}
//
//void QHerb::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
//{
//	painter->setPen(Qt::NoPen);
//	painter->setBrush(mBrush);
//	painter->drawPolygon(mShape);
//
//}
