#include "linemodel.h"
#include "lineitem.h"
#include "../../../../../MainWidgets/ImageViewer/igraphicsview.h"
#include "../../../../UndoService/Command/additemcommand.h"

void LineModel::mousePressed(const QPoint &mousePos, IGraphicsView *view) {
    if (isDrawing)
        return;
    x = mousePos.x();
    y = mousePos.y();
    item = new LineItem(this);
    item->setLine(x, y, x, y);
    item->setPen(pen);
    view->addItem(item);
    isDrawing = true;
}

void LineModel::mouseMoved(const QPoint &mousePos, IGraphicsView *view) {
    if (!isDrawing || !item)
        return;
    item->setLine(x, y, mousePos.x(), mousePos.y());
}

void LineModel::mouseReleased(const QPoint &mousePos, IGraphicsView *view) {
    isDrawing = false;
    if (x == mousePos.x() && y == mousePos.y() || !item) {
        delete item;
        item = nullptr;
        return;
    }
    item->setLine(x, y, mousePos.x(), mousePos.y());
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    new AddItemCommand(item);
}

void LineModel::setColor(const QColor &color) {
    pen.setColor(color);
    if (selectedItem)
        selectedItem->setPen(pen);
}

void LineModel::setThickness(const int &value) {
    thickness = value;
    pen.setWidth(thickness);
    if (selectedItem)
        selectedItem->setPen(pen);
}

QGraphicsLineItem *LineModel::getGraphicsItem() {
    return item;
}

void LineModel::onItemSelected(QGraphicsLineItem *graphicsLineItem) {
    selectedItem = graphicsLineItem;
    emit itemSelected();
}

void LineModel::onItemDeselected() {
    selectedItem = nullptr;
    emit itemDeselected();
}
