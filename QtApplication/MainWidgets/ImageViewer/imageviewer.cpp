#include "imageviewer.h"
#include "../../logger.h"

ImageViewer::ImageViewer(QWidget *parent) : view(new ImageViewerView(parent)), imageContainer(view->imageContainer),
                                            minScale(view->minScale), maxScale(view->maxScale),
                                            defaultScale(view->defaultScale), scaleValue(defaultScale),
                                            sliderDefaultValue(sliderMaxValue / 2), sliderMaxValue(view->sliderMaxValue) {
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

void ImageViewer::scaleImage(int newScaleValue) {
    imageContainer->scale((float) newScaleValue / 100);
}

void ImageViewer::adjustScrollBar(QScrollBar *scrollBar, float scaleFactor) {
    scrollBar->setValue(int(scaleFactor * (float) scrollBar->value()
                            + ((scaleFactor - 1) * (float) scrollBar->pageStep() / 2)));
}

void ImageViewer::setScaleValue(int value) {
    int oldScaleValue = scaleValue;
    if (value > sliderDefaultValue) {
        scaleValue = defaultScale + (value - sliderDefaultValue) * (maxScale - defaultScale) / 100;
    } else {
        scaleValue = minScale + value * (defaultScale - minScale) / 100;
    }
    view->slider->setToolTip(QString("%1").arg(scaleValue));
    scaleImage(scaleValue);
    float scaleFactor = (float) scaleValue / (float) oldScaleValue;
    adjustScrollBar(view->scrollArea->horizontalScrollBar(), scaleFactor);
    adjustScrollBar(view->scrollArea->verticalScrollBar(), scaleFactor);
    qDebug(ui()) << "Scaling image:" << scaleValue << "%";
}

void ImageViewer::adjustSize() {
    qDebug() << "Adjusting size";
}
