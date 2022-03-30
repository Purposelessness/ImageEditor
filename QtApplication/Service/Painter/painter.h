#ifndef IMAGEEDITOR_PAINTER_H
#define IMAGEEDITOR_PAINTER_H

#include "../../MainWidgets/ImageViewer/igraphicsview.h"

#include <QGraphicsScene>
#include <QPen>
#include <QBrush>

class Painter : public QObject {
Q_OBJECT

public:
    explicit Painter(IGraphicsView *graphicsView);

public slots:
    void onMousePressed(const QPoint& mousePos);
    void onMouseMoved(const QPoint& mousePos);
    void onMouseReleased(const QPoint& mousePos);

private:
    IGraphicsView *view;
};


#endif //IMAGEEDITOR_PAINTER_H
