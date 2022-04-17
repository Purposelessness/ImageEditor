#ifndef IMAGEEDITOR_TOOLMODEL_H
#define IMAGEEDITOR_TOOLMODEL_H


#include "../../../MainWidgets/ImageViewer/igraphicsview.h"

#include <QObject>

struct Coordinates {
    Coordinates(qreal x_0, qreal y_0, qreal x, qreal y) {
        this->x_0 = x_0;
        this->y_0 = y_0;
        this->x = x;
        this->y = y;
    }
    [[nodiscard]] bool isNull() const {
        return x_0 == x && y_0 == y;
    }
    qreal x_0, y_0, x, y;
};

class ToolModel : public QObject {
public:
    virtual void onMousePressed(const QPoint &mousePos, IGraphicsView *view) final;
    virtual void onMouseMoved(const QPoint &mousePos) final;
    virtual void onMouseReleased(const QPoint &mousePos) final;

protected:
    virtual QGraphicsItem *startDrawing(const Coordinates &coordinates) = 0;
    virtual void onDrawing(const Coordinates &coordinates) = 0;
    virtual void finishDrawing(const Coordinates &coordinates) = 0;

    static QRectF normalizeRect(qreal x_0, qreal y_0, qreal x, qreal y);

    QGraphicsItem *item;

private:
    bool isDrawing = false;
    int startX, startY;
};


#endif //IMAGEEDITOR_TOOLMODEL_H
