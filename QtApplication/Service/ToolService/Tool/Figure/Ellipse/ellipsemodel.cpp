#include "ellipsemodel.h"
#include "ellipseitem.h"

QAbstractGraphicsShapeItem *EllipseModel::drawItem(const QRectF &rect) {
    ellipse = new EllipseItem(this);
    ellipse->setRect(rect);
    return ellipse;
}

void EllipseModel::resizeItem(const QRectF &rect) {
    ellipse->setRect(rect);
}
