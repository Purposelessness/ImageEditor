#include "trianglemodel.h"

QAbstractGraphicsShapeItem *TriangleModel::drawItem(const QRectF &rect) {
    triangle = new TriangleItem(this);
    return triangle;
}

void TriangleModel::resizeItem(const QRectF &rect) {
    triangle->setRect(rect);
}
