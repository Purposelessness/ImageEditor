#ifndef IMAGEEDITOR_IMAGEREADER_H
#define IMAGEEDITOR_IMAGEREADER_H

#include <QImage>

class ImageReader {
public:
    static QImage loadImage(const QString& fileName);
};


#endif //IMAGEEDITOR_IMAGEREADER_H
