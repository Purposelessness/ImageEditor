#ifndef IMAGEEDITOR_PAINTER_H
#define IMAGEEDITOR_PAINTER_H

#include <QGraphicsScene>
#include <QPen>
#include <QBrush>

class Painter : public QObject {
Q_OBJECT

public:
    explicit Painter(QGraphicsScene *scene);

signals:
    void drawingFinished(QGraphicsItem *item);

public slots:
    void onMousePressed(const QPoint& mousePos);
    void onMouseMoved(const QPoint& mousePos);
    void onMouseReleased(const QPoint& mousePos);

private:
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipseItem;
    QPen defaultPen;
    QBrush defaultBrush;

    bool isDrawing = false;

    int x = 0, y = 0;
};


#endif //IMAGEEDITOR_PAINTER_H
