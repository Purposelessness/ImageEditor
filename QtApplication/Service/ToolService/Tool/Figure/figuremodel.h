#ifndef IMAGEEDITOR_FIGUREMODEL_H
#define IMAGEEDITOR_FIGUREMODEL_H


#include "../itoolmodel.h"

#include <QGraphicsItem>

struct FigureData;

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

class FigureModel : public IToolModel {
Q_OBJECT

public:
    void onMousePressed(const QPoint &mousePos, IGraphicsView *view) final;
    void onMouseMoved(const QPoint &mousePos) final;
    void onMouseReleased(const QPoint &mousePos) final;

    virtual FigureData getData() = 0;

signals:
    void itemSelected();
    void itemDeselected();

protected:
    virtual QGraphicsItem *startDrawing(const Coordinates &coordinates) = 0;
    virtual void onDrawing(const Coordinates &coordinates) = 0;
    virtual void finishDrawing(const Coordinates &coordinates) = 0;

    static QRectF normalizeRect(qreal x_0, qreal y_0, qreal x, qreal y);

private:
    QGraphicsItem *item = nullptr;

    bool isDrawing = false;
    int startX, startY;
};


#endif //IMAGEEDITOR_FIGUREMODEL_H
