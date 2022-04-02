#ifndef IMAGEEDITOR_SHAPEMODEL_H
#define IMAGEEDITOR_SHAPEMODEL_H

#include "../itoolmodel.h"

#include <QAbstractGraphicsShapeItem>

class ShapeModel : public IToolModel {
public:
    void mousePressed(const QPoint &mousePos, IGraphicsView *view) override;
    void mouseMoved(const QPoint &mousePos, IGraphicsView *view) override;
    void mouseReleased(const QPoint &mousePos, IGraphicsView *view) override;

    void setFillColor(const QColor &color);
    void setLineColor(const QColor &color);
    void setThickness(const int &value);

protected:
    virtual QAbstractGraphicsShapeItem *drawItem(const QRectF &rect) = 0;
    virtual void resizeItem(const QRectF &rect) = 0;

private:
    static QBrush brush;
    static QPen pen;
    static int thickness;

    QAbstractGraphicsShapeItem *item = nullptr;

    bool isDrawing = false;

    int x = 0, y = 0;
};


#endif //IMAGEEDITOR_SHAPEMODEL_H
