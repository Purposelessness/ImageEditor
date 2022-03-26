#include "imagereader.h"
#include <QImageReader>

QImage ImageReader::loadImage(const QString& fileName) {
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    return newImage.isNull() ? QImage() : newImage;
}
