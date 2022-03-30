#ifndef IMAGEEDITOR_SHAPEMODEL_H
#define IMAGEEDITOR_SHAPEMODEL_H

#include "../toolmodel.h"

#include <QGraphicsItem>

class ShapeModel : public IToolModel {
public:
    void mousePressed(const QPoint &mousePos, IGraphicsView *view) override;
    void mouseMoved(const QPoint &mousePos, IGraphicsView *view) override;
    void mouseReleased(const QPoint &mousePos, IGraphicsView *view) override;

    static void setFillColor(const QColor &color);
    static void setLineColor(const QColor &color);
    static void setThickness(const int &value);

protected:
    virtual QGraphicsItem *drawItem(const QRectF &rect, const QPen &pen, const QBrush &brush) = 0;
    virtual void resizeItem(const QRectF &rect) = 0;

private:
    static QBrush brush;
    static QPen pen;
    static int thickness;

    QGraphicsItem *item;

    bool isDrawing = false;

    int x = 0, y = 0;
};


#endif //IMAGEEDITOR_SHAPEMODEL_H
