#include "painter.h"

#include <QGraphicsEllipseItem>

Painter::Painter(QGraphicsScene *scene) : scene(scene), defaultPen(Qt::black), defaultBrush(Qt::blue), ellipseItem(nullptr) {}

void Painter::onMousePressed(const QPoint& mousePos) {
    if (isDrawing)
        return;
    x = mousePos.x();
    y = mousePos.y();
    auto rect = QRectF(x, y, 0, 0);
    ellipseItem = scene->addEllipse(rect, defaultPen, defaultBrush);
    isDrawing = true;
    qDebug() << "Pressed";
}

void Painter::onMouseMoved(const QPoint& mousePos) {
    if (!isDrawing || !ellipseItem)
        return;
    auto rect = QRectF(x, y, mousePos.x() - x, mousePos.y() - y);
    ellipseItem->setRect(rect);
}

void Painter::onMouseReleased(const QPoint& mousePos) {
    qDebug() << "Released";
    isDrawing = false;
    auto rect = QRectF(x, y, mousePos.x() - x, mousePos.y() - y);
    ellipseItem->setRect(rect);
    emit drawingFinished(ellipseItem);
    ellipseItem = nullptr;
}
