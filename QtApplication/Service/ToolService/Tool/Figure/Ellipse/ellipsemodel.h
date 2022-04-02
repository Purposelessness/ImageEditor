#ifndef IMAGEEDITOR_ELLIPSEMODEL_H
#define IMAGEEDITOR_ELLIPSEMODEL_H

#include "../shapemodel.h"

class EllipseModel : public ShapeModel {
public:
    explicit EllipseModel() = default;

protected:
    QAbstractGraphicsShapeItem *drawItem(const QRectF &rect) override;
    void resizeItem(const QRectF &rect) override;

private:
    QGraphicsEllipseItem *ellipse;
};


#endif //IMAGEEDITOR_ELLIPSEMODEL_H
