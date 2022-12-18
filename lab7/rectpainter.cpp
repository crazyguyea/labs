#include "rectpainter.h"

RectPainter::RectPainter(QObject *parent) :
    QObject(parent), QGraphicsItem(){}

RectPainter::~RectPainter(){}

QRectF RectPainter::boundingRect() const
{
    return QRectF (-20,-20,40,40);
}

void RectPainter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(-20,-20,40,40);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void RectPainter::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void RectPainter::mousePressEvent(QGraphicsSceneMouseEvent *event){ Q_UNUSED(event); }
