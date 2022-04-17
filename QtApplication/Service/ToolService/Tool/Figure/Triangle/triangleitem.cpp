#include "triangleitem.h"
#include "../ishapemodel.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

TriangleItem::TriangleItem(IShapeModel *model) : QAbstractGraphicsShapeItem(), model(model) {
    whiteSolidPen.setStyle(Qt::SolidLine);
    whiteSolidPen.setColor(Qt::white);
    whiteSolidPen.setWidth(0);

    blackDashPen.setStyle(Qt::DashLine);
    blackDashPen.setColor(Qt::black);
    blackDashPen.setWidth(0);
}

void TriangleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(pen());
    painter->setBrush(brush());
    painter->drawPath(geometry);

    if (option->state & (QStyle::State_Selected)) {
        drawMarquee(painter);
    }
}

void TriangleItem::drawMarquee(QPainter *painter) {
    painter->setBrush(Qt::NoBrush);
    painter->setPen(whiteSolidPen);
    painter->drawRect(rect);

    painter->setPen(blackDashPen);
    painter->drawRect(rect);
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
    auto path = calculateOuterBorder(rect, pen().widthF());
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

QPainterPath TriangleItem::calculateOuterBorder(const QRectF &rect, qreal penWidth) {
    qreal x_0, y_0, x, y;
    rect.getCoords(&x_0, &y, &x, &y_0);

    auto path = QPainterPath();
    qreal d = penWidth / 2;

    qreal a = (x - x_0) / 2;
    qreal x_mid = x_0 + a;
    qreal c = QLineF(x_0, y_0,  x_mid, y).length();
    qreal cotHalfAlpha = sqrt((c + a)/(c - a));
    qreal xShift = d * cotHalfAlpha;
    qreal yShift = d * c / a;

    path.moveTo(x_0 - xShift, y_0 + d);
    path.lineTo(x_mid, y - yShift);
    path.lineTo(x + xShift, y_0 + d);
    path.lineTo(x_0 - xShift, y_0 + d);

    return path;
}
