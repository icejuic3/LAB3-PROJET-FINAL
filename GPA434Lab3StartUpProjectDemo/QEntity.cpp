#include "QEntity.h"

QEntity::QEntity(QPointF const& position, qreal scale, QBrush const& brush, QGraphicsItem* parent)
    : QGraphicsItem(parent)
    , mQPen{ Qt::black }
    , mPosition{ position }
    , mColor{ Qt::white }
{
    setScale(scale);
    setPos(position);
    setColor(brush);
}

void QEntity::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(mBrush);
    painter->drawPolygon(mShape);
}

void QEntity::setColor(QBrush const& brush)
{
    mBrush = brush;
}

QRectF QEntity::boundingRect() const
{
    return mShape.boundingRect();
}


const QPointF& QEntity::getEntityPosition() const
{
    return mPosition;
}


