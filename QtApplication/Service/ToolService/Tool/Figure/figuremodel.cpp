#include "figuremodel.h"
#include "figure.h"
#include "../../../UndoService/Command/additemcommand.h"

void FigureModel::finishDrawing(const Coordinates &coordinates) {
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    new AddItemCommand(item);
    item->setSelected(true);
}
