#ifndef IMAGEEDITOR_IGRAPHICSVIEW_H
#define IMAGEEDITOR_IGRAPHICSVIEW_H


class QGraphicsScene;
class QGraphicsItem;
class QGraphicsPixmapItem;
class QPixmap;
class QRect;
class QRectF;

class IGraphicsView {
public:
    virtual void addItem(QGraphicsItem *item) = 0;
    virtual QGraphicsScene *getScene() = 0;
    virtual QGraphicsPixmapItem *getPixmapItem() = 0;
    virtual QPixmap grab(const QRect &rect) = 0;
    virtual void fitInView(const QRect &rect) = 0;
    virtual void fitInView(const QGraphicsItem *item) = 0;
};


#endif //IMAGEEDITOR_IGRAPHICSVIEW_H
