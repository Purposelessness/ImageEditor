#ifndef IMAGEEDITOR_IGRAPHICSVIEW_H
#define IMAGEEDITOR_IGRAPHICSVIEW_H

class QGraphicsScene;
class QGraphicsItem;

class IGraphicsView {
public:
    virtual void addItem(QGraphicsItem *item) = 0;
    virtual QGraphicsScene *getScene() = 0;
};

#endif //IMAGEEDITOR_IGRAPHICSVIEW_H
