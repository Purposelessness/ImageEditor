#include "shapemodel.h"
#include "../../../../MainWidgets/ImageViewer/igraphicsview.h"
#include "../../../../logger.h"
#include "../../../UndoService/Command/additemcommand.h"

#include <QPen>
#include <QBrush>
#include <QGraphicsScene>

QPen ShapeModel::pen = QPen();
QBrush ShapeModel::brush = QBrush();
int ShapeModel::thickness = 10;

void ShapeModel::mousePressed(const QPoint &mousePos, IGraphicsView *view) {
    if (isDrawing)
        return;
    x = mousePos.x();
    y = mousePos.y();
    auto rect = QRectF(x, y, 0, 0);
    item = drawItem(rect);
    item->setPen(pen);
    item->setBrush(brush);
    view->addItem(item);
    isDrawing = true;
}

void ShapeModel::mouseMoved(const QPoint &mousePos, IGraphicsView *view) {
    if (!isDrawing || !item)
        return;
    auto rect = QRectF(x, y, mousePos.x() - x, mousePos.y() - y);
    resizeItem(rect);
}

void ShapeModel::mouseReleased(const QPoint &mousePos, IGraphicsView *view) {
    isDrawing = false;
    qreal left, top, width, height;
    if (x <= mousePos.x()) {
        left = x;
        width = mousePos.x() - x;
    } else {
        left = mousePos.x();
        width = x - mousePos.x();
    }
    if (y <= mousePos.y()) {
        top = y;
        height = mousePos.y() - y;
    } else {
        top = mousePos.y();
        height = y - mousePos.y();
    }
    auto rect = QRectF(left, top, width, height);
    if (rect.isNull() || !item) {
        delete item;
        item = nullptr;
        return;
    }
    resizeItem(rect);
    new AddItemCommand(item);
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