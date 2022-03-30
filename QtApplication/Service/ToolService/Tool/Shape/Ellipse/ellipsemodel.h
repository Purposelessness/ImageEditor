#ifndef IMAGEEDITOR_ELLIPSEMODEL_H
#define IMAGEEDITOR_ELLIPSEMODEL_H

#include "../shapemodel.h"

class EllipseModel : public ShapeModel {
public:
    explicit EllipseModel() = default;

protected:
    QGraphicsItem *drawItem(const QRectF &rect, const QPen &pen, const QBrush &brush) override;
    void resizeItem(const QRectF &rect) override;

private:
    QGraphicsEllipseItem *ellipse;
};


#endif //IMAGEEDITOR_ELLIPSEMODEL_H
