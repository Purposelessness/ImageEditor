#include "figuremodel.h"
#include "figure.h"
#include "../../../UndoService/Command/additemcommand.h"

void FigureModel::finishDrawing(const Coordinates &coordinates) {
    item->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
    new AddItemCommand(item);
    item->setSelected(true);
}
