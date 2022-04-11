#ifndef IMAGEEDITOR_FIGUREMODEL_H
#define IMAGEEDITOR_FIGUREMODEL_H


#include "../itoolmodel.h"

#include <QGraphicsItem>

struct FigureData;

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
    virtual QGraphicsItem *startDrawing(QRectF rect) = 0;
    virtual void onDrawing(QRectF rect) = 0;
    virtual void finishDrawing(QRectF rect) = 0;

private:
    QGraphicsItem *item = nullptr;
    QRectF normalizeRect(const QPoint &mousePos) const;

    bool isDrawing = false;
    int x, y;
};


#endif //IMAGEEDITOR_FIGUREMODEL_H
