#ifndef IMAGEEDITOR_IGRAPHICSVIEW_H
#define IMAGEEDITOR_IGRAPHICSVIEW_H


class QGraphicsScene;
class QGraphicsItem;
class QGraphicsPixmapItem;
class QPixmap;
class QRect;
class QPointF;
class QPoint;

class IGraphicsView {
public:
    virtual void addItem(QGraphicsItem *item) = 0;
    virtual QGraphicsScene *getScene() = 0;
    virtual QGraphicsPixmapItem *getPixmapItem() = 0;
    virtual QPixmap grab(const QRect &rect) = 0;
};


#endif //IMAGEEDITOR_IGRAPHICSVIEW_H
