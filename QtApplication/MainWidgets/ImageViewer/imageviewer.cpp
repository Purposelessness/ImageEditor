#include "imageviewer.h"

ImageViewer::ImageViewer(QWidget *parent) : QWidget(parent), toolBar(new QToolBar()),
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

void ImageViewer::createActions() {
    zoomInAction = toolBar->addAction(tr("ZoomIn"), this, SLOT(onZoomInActionTriggered()));
    zoomInAction->setShortcut(QKeySequence::ZoomIn);

    zoomOutAction = toolBar->addAction(tr("ZoomOut"), this, SLOT(onZoomOutActionTriggered()));
    zoomOutAction->setShortcut(QKeySequence::ZoomOut);

    adjustSizeAction = toolBar->addAction(tr("AdjustSize"), this, SLOT(onAdjustSizeActionTriggered()));
    adjustSizeAction->setShortcut(Qt::CTRL | Qt::Key_R);

    setActionsEnabled(false);
}

void ImageViewer::setActionsEnabled(bool value) {
    for (auto action : toolBar->actions())
        action->setEnabled(value);
}

void ImageViewer::setImage(const QImage& newImage) {
    imageContainer->setImage(newImage);
    setActionsEnabled(true);
}

void ImageViewer::scale(float factor) {
    scaleFactor *= factor;
    imageContainer->scale(scaleFactor);
}

void ImageViewer::onZoomInActionTriggered() {

}

void ImageViewer::onZoomOutActionTriggered() {

}

void ImageViewer::onAdjustSizeActionTriggered() {

}
