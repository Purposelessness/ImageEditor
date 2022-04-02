#include "ellipsemodel.h"

QAbstractGraphicsShapeItem *EllipseModel::drawItem(const QRectF &rect) {
    ellipse = new QGraphicsEllipseItem(rect);
    return ellipse;
}

void EllipseModel::resizeItem(const QRectF &rect) {
    ellipse->setRect(rect);
}
