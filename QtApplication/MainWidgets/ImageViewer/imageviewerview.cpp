#include "imageviewerview.h"

ImageViewerView::ImageViewerView(QWidget *parent) : QWidget(parent), toolBar(new QToolBar()), slider(new QSlider(Qt::Horizontal)),
                                                    imageContainer(new ImageContainer()), layout(new QGridLayout(this)),
                                                    scrollArea(new QScrollArea()) {
    createActions();
    layout->setContentsMargins(5, 5, 5, 5);
    scrollArea->setBackgroundRole(QPalette::Mid);
    scrollArea->setAlignment(Qt::AlignCenter);
    scrollArea->setWidget(imageContainer);
    layout->addWidget(toolBar, 0, 0, Qt::AlignHCenter);
    layout->addWidget(scrollArea, 1, 0);
}

void ImageViewerView::createActions() {
    zoomInAction = toolBar->addAction(tr("ZoomIn"), this, SLOT(onZoomInActionTriggered()));
    zoomInAction->setShortcut(QKeySequence::ZoomIn);

    slider->setRange(0, 100);
    slider->setValue(50);
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(onSliderValueChanged(int)));
    toolBar->addWidget(slider);

    zoomOutAction = toolBar->addAction(tr("ZoomOut"), this, SLOT(onZoomOutActionTriggered()));
    zoomOutAction->setShortcut(QKeySequence::ZoomOut);

    adjustSizeAction = toolBar->addAction(tr("AdjustSize"), this, SLOT(onAdjustSizeActionTriggered()));
    adjustSizeAction->setShortcut(Qt::CTRL | Qt::Key_R);

    setActionsEnabled(false);
}

void ImageViewerView::setActionsEnabled(bool value) {
    for (auto action : toolBar->actions())
        action->setEnabled(value);
    slider->setEnabled(value);
}

void ImageViewerView::onZoomInActionTriggered() {
    emit zoomInActionTriggered();
}

void ImageViewerView::onZoomOutActionTriggered() {
    emit zoomOutActionTriggered();
}

void ImageViewerView::onAdjustSizeActionTriggered() {
    emit adjustSizeActionTriggered();
}

void ImageViewerView::onSliderValueChanged(int value) {
    emit sliderValueChanged(value);
}
