#include "imageviewer.h"

ImageViewer::ImageViewer(QWidget *parent) : QWidget(parent), imageContainer(new ImageContainer()), layout(new QGridLayout(this)),
                                            scrollArea(new QScrollArea()) {
    layout->setContentsMargins(5, 5, 5, 5);
    scrollArea->setBackgroundRole(QPalette::Mid);
    scrollArea->setAlignment(Qt::AlignCenter);
    scrollArea->setWidget(imageContainer);
    layout->addWidget(scrollArea);
}

void ImageViewer::setImage(const QImage& newImage) {
    imageContainer->setImage(newImage);
}
