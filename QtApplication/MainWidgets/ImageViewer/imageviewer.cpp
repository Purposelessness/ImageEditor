#include "imageviewer.h"

ImageViewer::ImageViewer(QWidget *parent) : QWidget(parent), canvas(new Canvas()), layout(new QGridLayout(this)),
                                            scrollArea(new QScrollArea()) {
    layout->setContentsMargins(5, 5, 5, 5);
    scrollArea->setBackgroundRole(QPalette::Mid);
    scrollArea->setAlignment(Qt::AlignCenter);
    scrollArea->setWidget(canvas);
    layout->addWidget(scrollArea);
}

void ImageViewer::setImage(const QImage& newImage) {
    canvas->setImage(newImage);
}
