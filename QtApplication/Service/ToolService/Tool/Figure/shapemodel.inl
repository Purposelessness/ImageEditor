#include "shapemodel.h"
#include "figure.h"

#include <QPen>
#include <QBrush>
#include <QGraphicsScene>

template<typename T>
QPen ShapeModel<T>::pen{};

template<typename T>
QBrush ShapeModel<T>::brush{};

template<typename T>
int ShapeModel<T>::thickness = 10;

template<typename T>
ShapeModel<T>::ShapeModel() : FigureModel() {
    static_assert(std::is_base_of<QAbstractGraphicsShapeItem, T>::value,
                  "Class must derive from QAbstractGraphicsShapeItem");
    pen.setJoinStyle(Qt::MiterJoin);
}

template<typename T>
QGraphicsItem *ShapeModel<T>::startDrawing(const Coordinates &coordinates) {
    item = new T(this);
    item->setRect(QRectF(coordinates.x_0, coordinates.y_0, 0, 0));
    item->setPen(pen);
    item->setBrush(brush);
    return item;
}

template<typename T>
void ShapeModel<T>::onDrawing(const Coordinates &coordinates) {
    item->setRect(normalizeRect(coordinates.x_0, coordinates.y_0, coordinates.x, coordinates.y));
}

template<typename T>
void ShapeModel<T>::finishDrawing(const Coordinates &coordinates) {
    item->setRect(normalizeRect(coordinates.x_0, coordinates.y_0, coordinates.x, coordinates.y));
    FigureModel::finishDrawing(coordinates);
    addCommand();
    item = nullptr;
}

template<typename T>
void ShapeModel<T>::setFillColor(const QColor &color) {
    if (color.isValid()) {
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(color);
    } else {
        brush.setStyle(Qt::NoBrush);
    }
    if (selectedItem)
        selectedItem->setBrush(brush);
}

template<typename T>
void ShapeModel<T>::setLineColor(const QColor &color) {
    if (color.isValid()) {
        pen.setColor(color);
    } else {
        pen.setColor(QColor(0, 0, 0, 0));
    }
    if (selectedItem)
        selectedItem->setPen(pen);
}

template<typename T>
void ShapeModel<T>::setThickness(const int &value) {
    thickness = value;
    pen.setWidth(thickness);
    if (selectedItem)
        selectedItem->setPen(pen);
}

template<typename T>
void ShapeModel<T>::onItemSelected(QAbstractGraphicsShapeItem *abstractGraphicsShapeItem) {
    selectedItem = abstractGraphicsShapeItem;
    emit itemSelected();
}

template<typename T>
void ShapeModel<T>::onItemDeselected() {
    selectedItem = nullptr;
    emit itemDeselected();
}

template<typename T>
FigureData ShapeModel<T>::getData() const {
    FigureData data{};
    if (!selectedItem) {
        data.type = FigureType::none;
        return data;
    }
    data.fillEnabled = selectedItem->brush().style() != Qt::NoBrush;
    if (data.fillEnabled)
        data.fillColor = selectedItem->brush().color();
    data.lineEnabled = selectedItem->pen().color() != QColor(0, 0, 0, 0);
    if (data.lineEnabled)
        data.lineColor = selectedItem->pen().color();
    data.thickness = selectedItem->pen().width();
    data.type = FigureType::shape;
    return data;
}

template<typename T>
void ShapeModel<T>::addCommand() {
    auto rect = item->mapToParent(item->boundingRect()).boundingRect().toRect();
    auto borderColor = pen.color().isValid() && pen.color().alpha() > 0 ? pen.color() : QColor();
    auto fillColor = brush.style() != Qt::NoBrush ? brush.color() : QColor();
    auto dataThickness = borderColor.isValid() ? thickness : 0;
    auto data = CommandFigureData{.rect = rect, .fillColor = fillColor, .borderColor = borderColor, .thickness = dataThickness};
    auto info = CommandInformation{.figureData = data, .type = type};
    new AddItemCommand(item, info);
}

template<typename T>
void ShapeModel<T>::setType(CommandType newType) {
    type = newType;
}
