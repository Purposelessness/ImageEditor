#ifndef IMAGEEDITOR_IMAGECONTAINER_H
#define IMAGEEDITOR_IMAGECONTAINER_H

#include <QGraphicsView>
#include <QGraphicsPixmapItem>

class ImageContainer : public QGraphicsView {
Q_OBJECT

public:
    explicit ImageContainer(QWidget *parent = nullptr);

    void setImage(const QImage& newImage);
    void scale(float newScaleValue);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QGraphicsScene *scene;
    QGraphicsPixmapItem *pixmapItem;
    QPixmap originalPixmap;
    QPixmap pixmap;

    float scaleValue = 1;
};


#endif //IMAGEEDITOR_IMAGECONTAINER_H
