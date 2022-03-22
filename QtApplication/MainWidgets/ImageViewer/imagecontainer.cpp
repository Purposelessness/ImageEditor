#include "imagecontainer.h"
#include "../../logger.h"

#include <QColorSpace>

ImageContainer::ImageContainer(QWidget *parent) : QLabel(parent) {
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    setScaledContents(true);
}

void ImageContainer::setImage(const QImage& newImage) {
    qDebug(ui()) << "Setting image with size" << newImage.size();
    originalPixmap = QPixmap::fromImage(newImage);
    pixmap = originalPixmap;
/*  Color space validity
    auto pixmap = new QPixmap(QPixmap::fromImage(newImage));
    image = pixmap->toImage();
    if (image.colorSpace().isValid())
    image.convertToColorSpace(QColorSpace::SRgb); */
    setPixmap(pixmap);
    resize(newImage.size());
}

void ImageContainer::scale(float scaleValue) {
    resize(scaleValue * pixmap.size());
}

void ImageContainer::adjustSize(const QSize &parentSize) {

}
