#ifndef IMAGEEDITOR_LINEMODEL_H
#define IMAGEEDITOR_LINEMODEL_H

#include "../../itoolmodel.h"

#include <QGraphicsLineItem>
#include <QPen>

class LineModel : public IToolModel {
Q_OBJECT

public:
    void mousePressed(const QPoint &mousePos, IGraphicsView *view) override;
    void mouseMoved(const QPoint &mousePos, IGraphicsView *view) override;
    void mouseReleased(const QPoint &mousePos, IGraphicsView *view) override;

    void setColor(const QColor &color);
    void setThickness(const int &value);

    void unlock();
    void lock();

signals:
    void lineDrawn();

private:
    QPen pen = QPen();
    int thickness = 10;

    QGraphicsLineItem *item = nullptr;

    bool isDrawing = false;

    int x = 0, y = 0;
};


#endif //IMAGEEDITOR_LINEMODEL_H
