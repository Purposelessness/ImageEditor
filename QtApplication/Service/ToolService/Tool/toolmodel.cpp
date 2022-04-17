#include "toolmodel.h"

#include <QGraphicsItem>
#include <QPoint>
#include <QRectF>

void ToolModel::onMousePressed(const QPoint &mousePos, IGraphicsView *view) {
    if (isDrawing)
        return;
    isDrawing = true;
    startX = mousePos.x();
    startY = mousePos.y();
    auto coordinates = Coordinates(startX, startY, startX, startY);
    item = startDrawing(coordinates);
    view->addItem(item);
}

void ToolModel::onMouseMoved(const QPoint &mousePos) {
    if (!isDrawing || !item)
        return;
    auto coordinates = Coordinates(startX, startY, mousePos.x(), mousePos.y());
    onDrawing(coordinates);
}

void ToolModel::onMouseReleased(const QPoint &mousePos) {
    if (!isDrawing || !item)
        return;
    isDrawing = false;
    auto coordinates = Coordinates(startX, startY, mousePos.x(), mousePos.y());
    if (coordinates.isNull()) {
        delete item;
        item = nullptr;
        return;
    }
    finishDrawing(coordinates);
    item = nullptr;
}

QRectF ToolModel::normalizeRect(qreal x_0, qreal y_0, qreal x, qreal y) {
    qreal left, top, width, height;
    if (x_0 <= x) {
        left = x_0;
        width = x - x_0;
    } else {
        left = x;
        width = x_0 - x;
    }
    if (y_0 <= y) {
        top = y_0;
        height = y - y_0;
    } else {
        top = y;
        height = y_0 - y;
    }
    auto rect = QRectF(left, top, width, height);
    return rect;
}
