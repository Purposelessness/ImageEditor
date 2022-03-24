#ifndef IMAGEEDITOR_IMAGEVIEWER_H
#define IMAGEEDITOR_IMAGEVIEWER_H

#include "imageviewerview.h"

#include <QScrollBar>

class ImageViewer : QObject {
Q_OBJECT

public:
    explicit ImageViewer(QWidget *parent = Q_NULLPTR);

    void setImage(const QImage& newImage);
    ImageViewerView *getView();

private slots:
    void adjustSize();
    void setScaleValue(int sliderValue);

private:
    void scaleView(float scaleFactor);
    void scaleImage(int newScaleValue);
    static void adjustScrollBar(QScrollBar *scrollBar, float scaleFactor);
    void resetScaleValue();
    void syncSlider();

    ImageViewerView *view;
    ImageContainer *imageContainer;

    const int defaultScale, minScale, maxScale;
    const int sliderMaxValue, sliderDefaultValue;
    int scaleValue;
};


#endif //IMAGEEDITOR_IMAGEVIEWER_H
