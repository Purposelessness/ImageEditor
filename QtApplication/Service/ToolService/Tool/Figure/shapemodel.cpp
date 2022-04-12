#include "shapemodel.h"
#include "figure.h"

#include <QPen>
#include <QBrush>
#include <QGraphicsScene>

QPen ShapeModel::pen = QPen();
QBrush ShapeModel::brush = QBrush();
int ShapeModel::thickness = 10;

ShapeModel::ShapeModel() : FigureModel() {
    pen.setJoinStyle(Qt::MiterJoin);
}

QGraphicsItem *ShapeModel::startDrawing(const Coordinates &coordinates) {
    item = drawItem(QRectF(coordinates.x_0, coordinates.y_0, 0, 0));
    item->setPen(pen);
    item->setBrush(brush);
    return item;
}

void ShapeModel::onDrawing(const Coordinates &coordinates) {
    auto normalizedRect = normalizeRect(coordinates.x_0, coordinates.y_0, coordinates.x, coordinates.y);
    resizeItem(normalizedRect);
}

void ShapeModel::finishDrawing(const Coordinates &coordinates) {
    auto normalizedRect = normalizeRect(coordinates.x_0, coordinates.y_0, coordinates.x, coordinates.y);
    resizeItem(normalizedRect);
}

void ShapeModel::setFillColor(const QColor &color) {
    if (color.isValid()) {
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(color);
    } else {
        brush.setStyle(Qt::NoBrush);
    }
    if (selectedItem)
        selectedItem->setBrush(brush);
}

void ShapeModel::setLineColor(const QColor &color) {
    if (color.isValid()) {
        pen.setColor(color);
    } else {
        pen.setColor(QColor(0, 0, 0, 0));
    }
    if (selectedItem)
        selectedItem->setPen(pen);
}

void ShapeModel::setThickness(const int &value) {
    thickness = value;
    pen.setWidth(thickness);
    if (selectedItem)
        selectedItem->setPen(pen);
}

void ShapeModel::onItemSelected(QAbstractGraphicsShapeItem *abstractGraphicsShapeItem) {
    selectedItem = abstractGraphicsShapeItem;
    emit itemSelected();
}

void ShapeModel::onItemDeselected() {
    selectedItem = nullptr;
    emit itemDeselected();
}

FigureData ShapeModel::getData() {
    FigureData data{};
    if (!selectedItem) {
        data.type = none;
        return data;
    }
    data.fillColor = selectedItem->brush().style() == Qt::NoBrush ? QColor() : selectedItem->brush().color();
    data.lineColor = selectedItem->pen().color() == QColor(0, 0, 0, 0) ? QColor() : selectedItem->pen().color();
    data.thickness = selectedItem->pen().width();
    data.type = shape;
    return data;
}
