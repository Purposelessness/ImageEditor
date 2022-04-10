#ifndef IMAGEEDITOR_SHAPEMODEL_H
#define IMAGEEDITOR_SHAPEMODEL_H


#include "../itoolmodel.h"

#include <QAbstractGraphicsShapeItem>

class ShapeModel : public IToolModel {
Q_OBJECT

public:
    void onMousePressed(const QPoint &mousePos, IGraphicsView *view) override;
    void onMouseMoved(const QPoint &mousePos) override;
    void onMouseReleased(const QPoint &mousePos) override;

    void setFillColor(const QColor &color);
    void setLineColor(const QColor &color);
    void setThickness(const int &value);

    void onItemSelected(QAbstractGraphicsShapeItem *abstractGraphicsShapeItem);
    void onItemDeselected();

signals:
    void itemSelected();
    void itemDeselected();

protected:
    virtual QAbstractGraphicsShapeItem *drawItem(const QRectF &rect) = 0;
    virtual void resizeItem(const QRectF &rect) = 0;

private:
    static QBrush brush;
    static QPen pen;
    static int thickness;

    QAbstractGraphicsShapeItem *item = nullptr, *selectedItem = nullptr;

    bool isDrawing = false;

    int x = 0, y = 0;
};


#endif //IMAGEEDITOR_SHAPEMODEL_H
