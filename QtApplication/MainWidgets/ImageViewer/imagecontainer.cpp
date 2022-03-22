#include "imagecontainer.h"
#include "../../logger.h"

#include <QColorSpace>

ImageContainer::ImageContainer(QWidget *parent) : QLabel(parent) {
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    setScaledContents(true);
}

void ImageContainer::setImage(const QImage& newImage) {
    qDebug(ui()) << "Setting image with size" << newImage.size();
    image = newImage;
/*  Color space validity
    auto pixmap = new QPixmap(QPixmap::fromImage(newImage));
    image = pixmap->toImage();
    if (image.colorSpace().isValid())
    image.convertToColorSpace(QColorSpace::SRgb); */
    setPixmap(QPixmap::fromImage(image));
    adjustSize();
    resize(newImage.size());
}

void ImageContainer::scale(float scaleFactor) {
    resize(scaleFactor * pixmap(Qt::ReturnByValue).size());
}
