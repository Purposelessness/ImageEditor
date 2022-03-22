#ifndef IMAGEEDITOR_IMAGEVIEWER_H
#define IMAGEEDITOR_IMAGEVIEWER_H

#include "imageviewerview.h"

class ImageViewer : QObject {
Q_OBJECT

public:
    explicit ImageViewer(QWidget *parent = Q_NULLPTR);

    void setImage(const QImage& newImage);
    ImageViewerView *getView();

private slots:
    void zoomIn();
    void zoomOut();
    void adjustSize();
    void setScaleValue(int value);

private:
    void scaleImage();

    ImageViewerView *view;
    ImageContainer *imageContainer;
    float scaleValues[10];
    float scaleValue = 1;
};


#endif //IMAGEEDITOR_IMAGEVIEWER_H
