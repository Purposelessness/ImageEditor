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

    [[nodiscard]] FigureData getData() const override;

protected:
    QGraphicsItem *startDrawing(const Coordinates &coordinates) override;
    void onDrawing(const Coordinates &coordinates) override;
    void finishDrawing(const Coordinates &coordinates) override;

private:
    QPen pen = QPen();
    int thickness = 10;

    QGraphicsLineItem *item = nullptr, *selectedItem = nullptr;
};


#endif //IMAGEEDITOR_LINEMODEL_H
