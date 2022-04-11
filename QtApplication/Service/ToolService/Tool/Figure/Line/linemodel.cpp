#include "linemodel.h"
#include "lineitem.h"
#include "../figure.h"

QGraphicsItem *LineModel::startDrawing(QRectF rect) {
    item = new LineItem(this);
    item->setLine(rect.x(), rect.y(), rect.x(), rect.y());
    item->setPen(pen);
    return item;
}

void LineModel::onDrawing(QRectF rect) {
    item->setLine(rect.x(), rect.y(), rect.x() + rect.width(), rect.y() + rect.height());
}

void LineModel::finishDrawing(QRectF rect) {
    item->setLine(rect.x(), rect.y(), rect.x() + rect.width(), rect.y() + rect.height());
    item = nullptr;
}

FigureData LineModel::getData() {
    FigureData data{};
    if (!selectedItem) {
        data.type = none;
        return data;
    }
    data.lineColor = selectedItem->pen().color();
    data.thickness = selectedItem->pen().width();
    data.type = line;
    return data;
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

void LineModel::onItemSelected(QGraphicsLineItem *graphicsLineItem) {
    selectedItem = graphicsLineItem;
    emit itemSelected();
}

void LineModel::onItemDeselected() {
    selectedItem = nullptr;
    emit itemDeselected();
}
