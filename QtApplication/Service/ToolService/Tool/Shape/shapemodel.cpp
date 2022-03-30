#include "shapemodel.h"
#include "../../../../MainWidgets/ImageViewer/igraphicsview.h"
#include "../../../../logger.h"
#include "../../../UndoService/Command/additemcommand.h"

#include <QPen>
#include <QBrush>
#include <QGraphicsScene>

void ShapeModel::mousePressed(const QPoint &mousePos, IGraphicsView *view) {
    if (isDrawing)
        return;
    x = mousePos.x();
    y = mousePos.y();
    auto rect = QRectF(x, y, 0, 0);
    item = drawItem(rect, pen, brush);
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
    auto rect = QRectF(x, y, mousePos.x() - x, mousePos.y() - y);
    if (rect.isNull()) {
        qDebug(core()) << "Rect is NULL";
        delete item;
        item = nullptr;
        return;
    }
    resizeItem(rect);
    new AddItemCommand(item);
    item = nullptr;
}

void ShapeModel::setFillColor(const QColor &color) {
    brush.setColor(color);
}

void ShapeModel::setLineColor(const QColor &color) {
    pen.setColor(color);
}

void ShapeModel::setThickness(const int &value) {
    thickness = value;
    pen.setWidth(thickness);
}
