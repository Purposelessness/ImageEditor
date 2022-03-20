#include "canvas.h"

#include <QGuiApplication>

Canvas::Canvas(QWidget *parent) : QWidget(parent), imageLabel(new QLabel()) {
    setMinimumSize(500, 500);
    this->setBackgroundRole(QPalette::Base);

    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);
}
