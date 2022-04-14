#include "triangleitem.h"
#include "trianglemodel.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

TriangleItem::TriangleItem(TriangleModel *model) : QAbstractGraphicsShapeItem(), model(model) {}

void TriangleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(pen());
    painter->setBrush(brush());
    painter->drawPath(geometry);

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
    auto correctRect = rect;
    qreal penWidth = pen().widthF() * 1.5;
    qreal top, right, bottom, left;
    rect.getCoords(&left, &top, &right, &bottom);
    correctRect.setTop(top - penWidth);
    correctRect.setRight(right + penWidth);
    correctRect.setBottom(bottom + penWidth);
    correctRect.setLeft(left - penWidth);
    return correctRect;
}

void TriangleItem::setRect(const QRectF &newRect) {
    newRect.getCoords(&x_0, &y, &x, &y_0);

    rect.setLeft(x_0);
    rect.setBottom(y_0);
    rect.setRight(x);
    rect.setTop(y);

    geometry.clear();
    geometry.moveTo(rect.bottomLeft());
    geometry.lineTo(QPointF(rect.center().x(), rect.top()));
    geometry.lineTo( rect.bottomRight());
    geometry.lineTo(rect.bottomLeft());
    update(boundingRect());
}

QPainterPath TriangleItem::shape() const {
    auto path = calculateFullPath(rect, pen().widthF());
    return path;
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

QPainterPath TriangleItem::calculateFullPath(const QRectF &rect, qreal penWidth) {
    qreal x_0, y_0, x, y;
    rect.getCoords(&x_0, &y, &x, &y_0);

    auto path = QPainterPath();

    qreal tanAlpha = 2 * rect.height() / rect.width();

    qreal halfAngleAlfa = qAtan(tanAlpha) / 2;
    qreal halfPenWidth = penWidth / 2;
    qreal xShift = halfPenWidth / qTan(halfAngleAlfa);
    qreal yShift = halfPenWidth;

    qreal halfAngleBeta = M_PI_2 - halfAngleAlfa;
    qreal c = yShift / qSin(halfAngleBeta);

    path.moveTo(x_0 - xShift, y_0 + yShift);
    path.lineTo(rect.center().x(), y - c);
    path.lineTo(x + xShift, y_0 + yShift);
    path.lineTo(x_0 - xShift, y_0 + yShift);

    return path;
}
