#ifndef IMAGEEDITOR_RECTMODEL_H
#define IMAGEEDITOR_RECTMODEL_H

#include "../shapemodel.h"

class RectModel : public ShapeModel {
protected:
    QAbstractGraphicsShapeItem *drawItem(const QRectF &rect) override;
    void resizeItem(const QRectF &rect) override;

private:
    QGraphicsRectItem *rectangle;
};


#endif //IMAGEEDITOR_RECTMODEL_H
