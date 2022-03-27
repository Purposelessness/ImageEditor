#include "painter.h"
#include "../UndoService/Command/additemcommand.h"

Painter::Painter(IGraphicsView *graphicsView) : scene(graphicsView->getScene()), graphicsView(graphicsView),
                                                defaultPen(Qt::black), defaultBrush(Qt::blue),
                                                ellipseItem(nullptr) {}

void Painter::onMousePressed(const QPoint& mousePos) {
    if (isDrawing)
        return;
    x = mousePos.x();
    y = mousePos.y();
    auto rect = QRectF(x, y, 0, 0);
    ellipseItem = scene->addEllipse(rect, defaultPen, defaultBrush);
    isDrawing = true;
}

void Painter::onMouseMoved(const QPoint& mousePos) {
    if (!isDrawing || !ellipseItem)
        return;
    auto rect = QRectF(x, y, mousePos.x() - x, mousePos.y() - y);
    ellipseItem->setRect(rect);
}

void Painter::onMouseReleased(const QPoint& mousePos) {
    isDrawing = false;
    auto rect = QRectF(x, y, mousePos.x() - x, mousePos.y() - y);
    ellipseItem->setRect(rect);
    new AddItemCommand(ellipseItem);
    emit drawingFinished(ellipseItem);
    ellipseItem = nullptr;
}
