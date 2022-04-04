#include "graphicstriangleitem.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

GraphicsTriangleItem::GraphicsTriangleItem(QGraphicsItem *parent) : QAbstractGraphicsShapeItem(parent) {}

void GraphicsTriangleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
//    auto rect = option->rect;
    auto rect = QRectF(option->rect.x() - 20, option->rect.y() - 20, 20, 20);
    polygon.replace(0, QPointF(rect.x() - rect.width(), rect.y() - rect.height()));
    polygon.replace(1, QPointF((float) rect.x() - (float) rect.width() / 2, rect.y()));
    polygon.replace(2, QPointF(rect.x(), rect.y() - rect.height()));
    auto pen = QPen(Qt::black);
    pen.setWidth(30);
    painter->setPen(pen);
    painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
}

QRectF GraphicsTriangleItem::boundingRect() const {
//    return QRectF{polygon.value(0), polygon.value(2)};
    qreal penWidth = 1;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

void GraphicsTriangleItem::setRect(const QRectF &rect) {
//    polygon.replace(0, QPointF(rect.x() - rect.width(), rect.y() - rect.height()));
//    polygon.replace(1, QPointF((float) rect.x() - (float) rect.width() / 2, rect.y()));
//    polygon.replace(2, QPointF(rect.x(), rect.y() - rect.height()));
}
