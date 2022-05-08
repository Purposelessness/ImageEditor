#include "figuremodel.h"
#include "figure.h"

void FigureModel::finishDrawing(const Coordinates &coordinates) {
    item->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
    item->setSelected(true);
}
