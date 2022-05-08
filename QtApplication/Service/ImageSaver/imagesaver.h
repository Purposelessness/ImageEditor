#ifndef IMAGEEDITOR_IMAGESAVER_H
#define IMAGEEDITOR_IMAGESAVER_H

#include <QImage>

class ImageSaver {
public:
    static void saveImage(const QImage& image);
    static void saveImageViaLib(const QString &srcImage);
};


#endif //IMAGEEDITOR_IMAGESAVER_H
