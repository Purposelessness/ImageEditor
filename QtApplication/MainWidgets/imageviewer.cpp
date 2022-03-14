#include <QGuiApplication>
#include "imageviewer.h"


ImageViewer::ImageViewer(QWidget *parent) : QWidget(parent) {
    setBackgroundColor(Qt::lightGray);
}

void ImageViewer::setBackgroundColor(QColor color) {
    QPalette palette = QGuiApplication::palette();
    palette.setColor(QPalette::Window, color);
    setAutoFillBackground(true);
    setPalette(palette);
}
