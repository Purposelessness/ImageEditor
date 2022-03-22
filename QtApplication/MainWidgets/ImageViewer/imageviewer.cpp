#include "imageviewer.h"

ImageViewer::ImageViewer(QWidget *parent) : QWidget(parent), imageContainer(new ImageContainer()), layout(new QGridLayout(this)),
                                            scrollArea(new QScrollArea()) {
    layout->setContentsMargins(5, 5, 5, 5);
    scrollArea->setBackgroundRole(QPalette::Mid);
    scrollArea->setAlignment(Qt::AlignCenter);
    scrollArea->setWidget(imageContainer);
    layout->addWidget(scrollArea, 1, 0, Qt::AlignCenter);
}

void ImageViewer::setImage(const QImage& newImage) {
    imageContainer->setImage(newImage);
}

void ImageViewer::scale(float factor) {
    scaleFactor *= factor;
    imageContainer->scale(scaleFactor);
}
