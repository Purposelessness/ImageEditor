#include <QIntValidator>
#include "imageviewerview.h"

ImageViewerView::ImageViewerView(QWidget *parent) : QWidget(parent), toolBar(new QToolBar()),
                                                    slider(new QSlider(Qt::Horizontal)),
                                                    imageContainer(new ImageContainer()), layout(new QGridLayout(this)),
                                                    scrollArea(new QScrollArea()) {
    createActions();
    setActionsEnabled(false);
    layout->setContentsMargins(5, 5, 5, 5);
    scrollArea->setBackgroundRole(QPalette::Mid);
    scrollArea->setAlignment(Qt::AlignCenter);
    scrollArea->setWidget(imageContainer);
    layout->addWidget(toolBar, 0, 0, Qt::AlignHCenter);
    layout->addWidget(scrollArea, 1, 0);
}

void ImageViewerView::createActions() {
    zoomOutAction = toolBar->addAction(tr("ZoomOut"), this, SLOT(onZoomOutActionTriggered()));
    zoomOutAction->setShortcut(QKeySequence::ZoomOut);

    slider->setRange(sliderMinValue, sliderMaxValue);
    slider->setValue(sliderMaxValue / 2);
    slider->setTickInterval(sliderMaxValue / 2);
    slider->setTickPosition(QSlider::TicksBelow);
    slider->tickPosition();
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(onSliderValueChanged(int)));
    toolBar->addWidget(slider);

    zoomInAction = toolBar->addAction(tr("ZoomIn"), this, SLOT(onZoomInActionTriggered()));
    zoomInAction->setShortcut(QKeySequence::ZoomIn);

    adjustSizeAction = toolBar->addAction(tr("AdjustSize"), this, SLOT(onAdjustSizeActionTriggered()));
    adjustSizeAction->setShortcut(Qt::CTRL | Qt::Key_Equal);
}

void ImageViewerView::setActionsEnabled(bool value) {
    for (auto action: toolBar->actions())
        action->setEnabled(value);
}

void ImageViewerView::setSliderValue(int value) {
    slider->setValue(value);
}

void ImageViewerView::onZoomOutActionTriggered() {
    setSliderValue(slider->value() - zoomStep);
}

void ImageViewerView::onZoomInActionTriggered() {
    setSliderValue(slider->value() + zoomStep);
}

void ImageViewerView::onAdjustSizeActionTriggered() {
    emit adjustSizeActionTriggered();
}

void ImageViewerView::onSliderValueChanged(int value) {
    emit sliderValueChanged(value);
}
