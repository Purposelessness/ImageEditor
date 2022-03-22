#include "imageviewer.h"

ImageViewer::ImageViewer(QWidget *parent) : view(new ImageViewerView(parent)), imageContainer(view->imageContainer) {
    connect(view, SIGNAL(zoomInActionTriggered()), this, SLOT(zoomIn()));
    connect(view, SIGNAL(zoomOutActionTriggered()), this, SLOT(zoomOut()));
    connect(view, SIGNAL(adjustSizeActionTriggered()), this, SLOT(adjustSize()));
    connect(view, SIGNAL(sliderValueChanged(int)), this, SLOT(setScaleValue(int)));
}

void ImageViewer::setImage(const QImage& newImage) {
    imageContainer->setImage(newImage);
    view->setActionsEnabled(true);
}

ImageViewerView *ImageViewer::getView() {
    return view;
}

void ImageViewer::scaleImage() {
    imageContainer->scale(scaleValue);
    qDebug() << scaleValue;
}

void ImageViewer::zoomIn() {
    if (scaleValue < .25)
        scaleValue = .25;
    else if (scaleValue < .5)
        scaleValue = .5;
    else if (scaleValue < 1)
        scaleValue = 1;
    else
        scaleValue += .5;
    scaleImage();
}

void ImageViewer::zoomOut() {
    if (scaleValue <= .25)
        scaleValue = .1;
    else if (scaleValue <= .5)
        scaleValue = .25;
    else if (scaleValue <= 1)
        scaleValue = .5;
    else
        scaleValue -= .25;
    scaleImage();
}

void ImageViewer::setScaleValue(int value) {
    if (value == 0)
        scaleValue = 0.1;
    else if (value <= 25)
        scaleValue = 0.5;
    else if (value >= 75)
        scaleValue = 5;
    else if (value == 100)
        scaleValue = 10;
    else
        scaleValue = 1;
    scaleImage();
}

void ImageViewer::adjustSize() {
    qDebug() << "Adjusting size";
}
