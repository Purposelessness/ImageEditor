#ifndef IMAGEEDITOR_IMAGESAVER_H
#define IMAGEEDITOR_IMAGESAVER_H

#include <QImage>

class ImageSaver {
public:
    static void saveImage(const QImage& image, const QString &destFilePath = QString());
    static void saveImageViaLib(const QString &srcImage, const QString &destFilePath = QString());
};


#endif //IMAGEEDITOR_IMAGESAVER_H
