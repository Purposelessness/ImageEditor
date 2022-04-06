#include "rectmodel.h"
#include "rectitem.h"

QAbstractGraphicsShapeItem *RectModel::drawItem(const QRectF &rect) {
    rectangle = new RectItem(this);
    return rectangle;
}

void RectModel::resizeItem(const QRectF &rect) {
    rectangle->setRect(rect);
}
