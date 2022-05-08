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
    auto p1 = QPointF(coordinates.x_0, coordinates.y_0).toPoint();
    auto p2 = QPointF(coordinates.x, coordinates.y).toPoint();
    if (p1.x() > p2.x()) {
        auto t = p2;
        p2 = p1;
        p1 = t;
    }
    auto data = CommandLineData{.x1 = p1.x(), .y1 = p1.y(), .x2 = p2.x(), .y2 = p2.y(), .color = pen.color(), .thickness = thickness};
    auto info = CommandInformation{.lineData = data, .type = CommandType::line};
    new AddItemCommand(item, info);
}
