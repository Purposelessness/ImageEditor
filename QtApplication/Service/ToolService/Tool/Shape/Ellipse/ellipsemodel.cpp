#include "ellipsemodel.h"

QAbstractGraphicsShapeItem *EllipseModel::drawItem(const QRectF &rect, const QPen &pen, const QBrush &brush) {
    ellipse = new QGraphicsEllipseItem(rect);
    ellipse->setPen(pen);
    ellipse->setBrush(brush);
    return ellipse;
}

void EllipseModel::resizeItem(const QRectF &rect) {
    ellipse->setRect(rect);
}
