#ifndef IMAGEEDITOR_TOOLMODEL_H
#define IMAGEEDITOR_TOOLMODEL_H

class IGraphicsView;
class QPoint;

class IToolModel {
public:
    virtual void mousePressed(const QPoint &mousePos, IGraphicsView *view = nullptr) = 0;
    virtual void mouseMoved(const QPoint &mousePos, IGraphicsView *view = nullptr) = 0;
    virtual void mouseReleased(const QPoint &mousePos, IGraphicsView *view = nullptr) = 0;
};


#endif //IMAGEEDITOR_TOOLMODEL_H
