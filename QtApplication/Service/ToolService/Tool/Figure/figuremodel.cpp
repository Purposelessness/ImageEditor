#include "figuremodel.h"
#include "figure.h"
#include "../../../../MainWidgets/ImageViewer/igraphicsview.h"
#include "../../../UndoService/Command/additemcommand.h"

void FigureModel::onMousePressed(const QPoint &mousePos, IGraphicsView *view) {
    if (isDrawing)
        return;
    isDrawing = true;
    x = mousePos.x();
    y = mousePos.y();
    auto rect = QRectF(x, y, 0, 0);
    item = startDrawing(rect);
    view->addItem(item);
}

void FigureModel::onMouseMoved(const QPoint &mousePos) {
    if (!isDrawing || !item)
        return;
    auto rect = normalizeRect(mousePos);
    onDrawing(rect);
}

void FigureModel::onMouseReleased(const QPoint &mousePos) {
    if (!isDrawing || !item)
        return;
    isDrawing = false;
    auto rect = normalizeRect(mousePos);
    if (rect.isNull()) {
        delete item;
        item = nullptr;
        return;
    }
    finishDrawing(rect);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    new AddItemCommand(item);
    item->setSelected(true);
    item = nullptr;
}

QRectF FigureModel::normalizeRect(const QPoint &mousePos) const {
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
    return rect;
}
