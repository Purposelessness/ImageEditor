#include "triangleitem.h"
#include "trianglemodel.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

TriangleItem::TriangleItem(TriangleModel *model) : QAbstractGraphicsShapeItem(), model(model) {}

void TriangleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(pen());
    painter->setBrush(brush());
    painter->drawPolygon(geometry);

    if (option->state & (QStyle::State_Selected)) {
        QPen dotPen = QPen(Qt::SolidLine);
        dotPen.setColor(Qt::white);
        dotPen.setWidth(1);
        painter->setPen(dotPen);
        painter->setBrush(Qt::NoBrush);
        painter->drawRect(rect);

        dotPen.setStyle(Qt::DashLine);
        dotPen.setColor(Qt::black);
        painter->setPen(dotPen);
        painter->drawRect(rect);
    }
}

QRectF TriangleItem::boundingRect() const {
    return rect;
}

void TriangleItem::setRect(const QRectF &newRect) {
    rect.setLeft(newRect.left());
    rect.setBottom(newRect.bottom());
    rect.setRight(newRect.right());
    rect.setTop(newRect.top());

    geometry.clear();
    geometry.append(rect.bottomLeft());
    geometry.append(QPointF(rect.center().x(), rect.top()));
    geometry.append( rect.bottomRight());
    update();
}

QVariant TriangleItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) {
    if (change == QGraphicsItem::ItemSelectedChange) {
        if (value == true) {
            model->onItemSelected(this);
        } else {
            model->onItemDeselected();
        }
    }
    return QGraphicsItem::itemChange(change, value);
}
