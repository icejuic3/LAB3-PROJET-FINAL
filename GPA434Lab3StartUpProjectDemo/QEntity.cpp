#include "QEntity.h"

QEntity::QEntity(QPointF const& position, QGraphicsItem* parent)
    : QGraphicsItem(parent)
    , mFamilyId{ "entity" }
    , mQPen{ Qt::black }
    , mPosition{ position }
    , mColor{ Qt::white }
{
    setPos(position);
}

QPointF& QEntity::getPosition()
{
    QPointF bob{ 2,2 };
    return bob;
}
