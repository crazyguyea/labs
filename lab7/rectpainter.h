#ifndef RECTPAINTER_H
#define RECTPAINTER_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

class RectPainter : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit RectPainter(QObject *parent = 0);
    ~RectPainter();

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // RECTPAINTER_H
