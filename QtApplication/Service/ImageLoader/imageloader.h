#ifndef IMAGEEDITOR_IMAGELOADER_H
#define IMAGEEDITOR_IMAGELOADER_H

#include <QImage>

struct ImageLoaderOut {
    QImage image{};
    QString imagePath{};
};

class ImageLoader {
public:
    static ImageLoaderOut loadImage();
};


#endif //IMAGEEDITOR_IMAGELOADER_H
