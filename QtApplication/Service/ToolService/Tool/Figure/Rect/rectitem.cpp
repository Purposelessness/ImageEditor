#include "rectitem.h"
#include "../ishapemodel.h"

RectItem::RectItem(IShapeModel *newModel) : QGraphicsRectItem(), model(newModel) {}

QVariant RectItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) {
    if (change == QGraphicsItem::ItemSelectedChange) {
        if (value == true) {
            model->onItemSelected(this);
        } else {
            model->onItemDeselected();
        }
    }
    return QGraphicsItem::itemChange(change, value);
}
