#ifndef IMAGEEDITOR_TRIANGLEMODEL_H
#define IMAGEEDITOR_TRIANGLEMODEL_H


#include "../shapemodel.h"
#include "triangleitem.h"

class TriangleModel : public ShapeModel {
protected:
    QAbstractGraphicsShapeItem *drawItem(const QRectF &rect) override;
    void resizeItem(const QRectF &rect) override;

private:
    TriangleItem *triangle;
};


#endif //IMAGEEDITOR_TRIANGLEMODEL_H
