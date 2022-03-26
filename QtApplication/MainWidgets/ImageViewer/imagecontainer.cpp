#include "imagecontainer.h"
#include "../../logger.h"

#include <QColorSpace>

ImageContainer::ImageContainer(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene),
                                                  pixmapItem(nullptr) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setViewportMargins(-2, -2, -2, -2);
    setBackgroundRole(QPalette::Mid);
    setScene(scene);
}

void ImageContainer::setImage(const QImage &newImage) {
    scaleValue = 1;
    qDebug(ui()) << "Setting image with size" << newImage.size();
    originalPixmap = QPixmap::fromImage(newImage);
    pixmap = originalPixmap;
/*  Color space validity
    auto pixmap = new QPixmap(QPixmap::fromImage(newImage));
    image = pixmap->toImage();
    if (image.colorSpace().isValid())
    image.convertToColorSpace(QColorSpace::SRgb); */
    pixmapItem = new QGraphicsPixmapItem;
    pixmapItem->setPixmap(pixmap);
    pixmapItem->setTransformationMode(Qt::SmoothTransformation);
    resize(pixmap.size());
    scene->addItem(pixmapItem);
}

void ImageContainer::scale(float newScaleValue) {
    scaleValue = newScaleValue;
    resize(scaleValue * pixmap.size());
}

void ImageContainer::resizeEvent(QResizeEvent *event) {
    if (pixmapItem)
        pixmapItem->setScale(scaleValue);
    setSceneRect(contentsRect());
    QGraphicsView::resizeEvent(event);
}
