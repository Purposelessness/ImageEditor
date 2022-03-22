#include "imageviewer.h"

ImageViewer::ImageViewer(QWidget *parent) : view(new ImageViewerView(parent)), imageContainer(view->imageContainer) {
}

void ImageViewer::setImage(const QImage& newImage) {
    imageContainer->setImage(newImage);
    view->setActionsEnabled(true);
}

void ImageViewer::scale(float factor) {
    scaleFactor *= factor;
    imageContainer->scale(scaleFactor);
}

ImageViewerView *ImageViewer::getView() {
    return view;
}
