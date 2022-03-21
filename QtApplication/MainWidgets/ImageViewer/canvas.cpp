#include "canvas.h"
#include "../../Logger/logger.h"

#include <QColorSpace>

Canvas::Canvas(QWidget *parent) : QWidget(parent), imageLabel(new QLabel(this)) {
    resize(700, 500);
    this->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);
}

void Canvas::setImage(const QImage &newImage) {
    qDebug(ui()) << "Setting image with size" << newImage.size();
    image = newImage;
    auto pixmap = new QPixmap(QPixmap::fromImage(newImage));
    image = pixmap->toImage();
    if (image.colorSpace().isValid())
        image.convertToColorSpace(QColorSpace::SRgb);

    imageLabel->setPixmap(QPixmap::fromImage(image));
    imageLabel->adjustSize();
    resize(newImage.size());
    imageLabel->resize(newImage.size());
}
