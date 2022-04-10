#ifndef IMAGEEDITOR_ITOOLMODEL_H
#define IMAGEEDITOR_ITOOLMODEL_H

#include <QObject>

class IGraphicsView;
class QPoint;

class IToolModel : public QObject {
Q_OBJECT

public:
    virtual void onMousePressed(const QPoint &mousePos, IGraphicsView *view) = 0;
    virtual void onMouseMoved(const QPoint &mousePos) = 0;
    virtual void onMouseReleased(const QPoint &mousePos) = 0;
};


#endif //IMAGEEDITOR_ITOOLMODEL_H
