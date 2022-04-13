#ifndef IMAGEEDITOR_SHAPEMODEL_H
#define IMAGEEDITOR_SHAPEMODEL_H


#include "figuremodel.h"

#include <QAbstractGraphicsShapeItem>

class ShapeModel : public FigureModel {
Q_OBJECT

public:
    ShapeModel();

    void setFillColor(const QColor &color = QColor());
    void setLineColor(const QColor &color = QColor());
    void setThickness(const int &value);

    [[nodiscard]] FigureData getData() const override;
    void onItemSelected(QAbstractGraphicsShapeItem *abstractGraphicsShapeItem);
    void onItemDeselected();

protected:
    QGraphicsItem *startDrawing(const Coordinates &coordinates) override;
    void onDrawing(const Coordinates &coordinates) override;
    void finishDrawing(const Coordinates &coordinates) override;

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
