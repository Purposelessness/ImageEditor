#ifndef IMAGEEDITOR_LINEMODEL_H
#define IMAGEEDITOR_LINEMODEL_H

#include "../figuremodel.h"

#include <QGraphicsLineItem>
#include <QPen>

class LineModel : public FigureModel {
Q_OBJECT

public:
    void setColor(const QColor &color);
    void setThickness(const int &value);

    void onItemSelected(QGraphicsLineItem *graphicsLineItem);
    void onItemDeselected();

    FigureData getData() override;

protected:
    QGraphicsItem *startDrawing(QRectF rect) override;
    void onDrawing(QRectF rect) override;
    void finishDrawing(QRectF rect) override;

private:
    QPen pen = QPen();
    int thickness = 10;

    QGraphicsLineItem *item = nullptr, *selectedItem = nullptr;
};


#endif //IMAGEEDITOR_LINEMODEL_H
