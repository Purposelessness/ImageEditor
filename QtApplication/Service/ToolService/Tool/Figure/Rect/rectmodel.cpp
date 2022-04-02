#include "rectmodel.h"

QAbstractGraphicsShapeItem *RectModel::drawItem(const QRectF &rect) {
    rectangle = new QGraphicsRectItem();
    return rectangle;
}

void RectModel::resizeItem(const QRectF &rect) {
    rectangle->setRect(rect);
}
