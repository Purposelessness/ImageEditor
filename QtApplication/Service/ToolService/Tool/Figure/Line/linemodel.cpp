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
    FigureModel::finishDrawing(coordinates);
    addCommand(coordinates);
    item = nullptr;
}

FigureData LineModel::getData() const {
    FigureData data{};
    if (!selectedItem) {
        data.type = FigureType::none;
        return data;
    }
    data.lineColor = selectedItem->pen().color();
    data.thickness = selectedItem->pen().width();
    data.type = FigureType::line;
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

void LineModel::addCommand(const Coordinates &coordinates) {
    auto data = item ? CommandLineData{item}
                     : CommandLineData{QPoint{static_cast<int>(coordinates.x_0), static_cast<int>(coordinates.y_0)},
                                       QPoint{static_cast<int>(coordinates.x), static_cast<int>(coordinates.y)},
                                       item->pen().color(), item->pen().width()};
    auto info = CommandInformation{.lineData = data, .type = CommandType::line};
    new AddItemCommand(item, info);
}
