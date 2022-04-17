#include "ellipseitem.h"
#include "../ishapemodel.h"

EllipseItem::EllipseItem(IShapeModel *newModel) : QGraphicsEllipseItem(), model(newModel) {}

QVariant EllipseItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) {
    if (change == QGraphicsItem::ItemSelectedChange) {
        if (value == true) {
            model->onItemSelected(this);
        } else {
            model->onItemDeselected();
        }
    }
    return QGraphicsItem::itemChange(change, value);
}
