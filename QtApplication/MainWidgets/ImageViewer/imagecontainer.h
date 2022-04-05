#ifndef IMAGEEDITOR_IMAGECONTAINER_H
#define IMAGEEDITOR_IMAGECONTAINER_H

#include "igraphicsview.h"
#include "../../Service/Painter/painter.h"

#include <QGraphicsView>
#include <QGraphicsPixmapItem>

class ImageContainer : public QGraphicsView, public IGraphicsView {
Q_OBJECT

public:
    explicit ImageContainer(QWidget *parent = nullptr);

    void setImage(const QImage& newImage);
    void scale(float newScaleValue);

    void addItem(QGraphicsItem *item) override;
    QGraphicsScene *getScene() override;

signals:
    void mousePressed(const QPoint& mousePos);
    void mouseMoved(const QPoint& mousePos);
    void mouseReleased(const QPoint& mousePos);

public slots:
    void onDrawingFinished(QGraphicsItem *item);

protected:
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    QGraphicsScene *scene;
    QGraphicsPixmapItem *pixmapItem;
    Painter painter;
    QPixmap pixmap;
    QPainterPath painterPath;

    float scaleValue = 1;
    const int selectRadius = 5;
};


#endif //IMAGEEDITOR_IMAGECONTAINER_H
