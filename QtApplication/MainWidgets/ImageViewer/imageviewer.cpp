#include "imageviewer.h"
#include "../../logger.h"

#include <cmath>

ImageViewer::ImageViewer(QWidget *parent) : view(new ImageViewerView(parent)), imageContainer(view->imageContainer),
                                            minScale(view->minScale), maxScale(view->maxScale),
                                            defaultScale(view->defaultScale), scaleValue(defaultScale),
                                            sliderDefaultValue(sliderMaxValue / 2),
                                            sliderMaxValue(view->sliderMaxValue) {
    connect(view, SIGNAL(adjustSizeActionTriggered()), this, SLOT(adjustSize()));
    connect(view, SIGNAL(sliderValueChanged(int)), this, SLOT(setScaleValue(int)));
}

void ImageViewer::setImage(const QImage& newImage) {
    imageContainer->setImage(newImage);
    view->setActionsEnabled(true);
    resetScaleValue();
    adjustSize();
}

ImageViewerView *ImageViewer::getView() {
    return view;
}

void ImageViewer::scaleView(float scaleFactor) {
    scaleImage(scaleValue);
    adjustScrollBar(view->scrollArea->horizontalScrollBar(), scaleFactor);
    adjustScrollBar(view->scrollArea->verticalScrollBar(), scaleFactor);
    qDebug(ui()) << "Scaling view. Scale value is" << scaleValue << "%, scaleFactor is" << scaleFactor;
}

void ImageViewer::resetScaleValue() {
    view->resetScaleValue();
    scaleValue = defaultScale;
}

void ImageViewer::scaleImage(int newScaleValue) {
    imageContainer->scale((float) newScaleValue / 100);
}

void ImageViewer::adjustScrollBar(QScrollBar *scrollBar, float scaleFactor) {
    scrollBar->setValue(int(scaleFactor * (float) scrollBar->value()
                            + ((scaleFactor - 1) * (float) scrollBar->pageStep() / 2)));
}

void ImageViewer::setScaleValue(int sliderValue) {
    int oldScaleValue = scaleValue;
    if (sliderValue > sliderDefaultValue) {
        scaleValue = defaultScale + (sliderValue - sliderDefaultValue) * (maxScale - defaultScale) / 100;
    } else {
        scaleValue = minScale + sliderValue * (defaultScale - minScale) / 100;
    }
    view->slider->setToolTip(QString("%1").arg(scaleValue));
    float scaleFactor = (float) scaleValue / (float) oldScaleValue;
    scaleView(scaleFactor);
}

void ImageViewer::adjustSize() {
    float scaleFactor;
    QSize imageSize = imageContainer->size();
    QSize viewSize = view->size();
    scaleFactor = 0.9f * std::fmin((float) viewSize.height() / (float) imageSize.height(),
                                   (float) viewSize.width() / (float) imageSize.width());
    scaleValue = (int) ((float) scaleValue * scaleFactor);
    syncSlider();
}

void ImageViewer::syncSlider() {
    int sliderValue;
    if (scaleValue > defaultScale) {
        sliderValue = ((scaleValue - defaultScale) * 100 / (maxScale - defaultScale)) + sliderDefaultValue;
    } else {
        sliderValue = (scaleValue - minScale) * 100 / (defaultScale - minScale);
    }
    view->setSliderValue(sliderValue);
}
