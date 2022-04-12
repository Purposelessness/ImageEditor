#include "linemodel.h"
#include "lineitem.h"
#include "../figure.h"

QGraphicsItem *LineModel::startDrawing(const Coordinates &coordinates) {
    item = new LineItem(this);
    item->setLine(coordinates.x_0, coordinates.y_0, coordinates.x, coordinates.y);
    item->setPen(pen);
    return item;
}

void LineModel::onDrawing(const Coordinates &coordinates) {
    item->setLine(coordinates.x_0, coordinates.y_0, coordinates.x, coordinates.y);
}

void LineModel::finishDrawing(const Coordinates &coordinates) {
    item->setLine(coordinates.x_0, coordinates.y_0, coordinates.x, coordinates.y);
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
