#ifndef IMAGEEDITOR_FIGUREMODEL_H
#define IMAGEEDITOR_FIGUREMODEL_H


#include "../toolmodel.h"

#include <QGraphicsItem>

struct FigureData;

class FigureModel : public ToolModel {
Q_OBJECT

public:
    [[nodiscard]] virtual FigureData getData() const = 0;

protected:
    QGraphicsItem *startDrawing(const Coordinates &coordinates) override = 0;
    void onDrawing(const Coordinates &coordinates) override = 0;
    void finishDrawing(const Coordinates &coordinates) override;

signals:
    void itemSelected();
    void itemDeselected();
};


#endif //IMAGEEDITOR_FIGUREMODEL_H
