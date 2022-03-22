#include "imagewriter.h"
#include "../../logger.h"

void ImageWriter::saveImage(const QImage& image) {
    qInfo(fileSystem()) << "File saved!";
}
