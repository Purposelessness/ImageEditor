#ifndef IMAGEEDITOR_IMAGEVIEWER_H
#define IMAGEEDITOR_IMAGEVIEWER_H

#include "imageviewerview.h"

class ImageViewer {
public:
    explicit ImageViewer(QWidget *parent = Q_NULLPTR);

    void setImage(const QImage& newImage);
    void scale(float factor);
    ImageViewerView *getView();

private:
    ImageViewerView *view;
    ImageContainer *imageContainer;
    float scaleFactor = 1;
};


#endif //IMAGEEDITOR_IMAGEVIEWER_H
