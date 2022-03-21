#ifndef IMAGEEDITOR_IMAGEVIEWER_H
#define IMAGEEDITOR_IMAGEVIEWER_H

#include "imagecontainer.h"

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>

class ImageViewer : public QWidget {
public:
    explicit ImageViewer(QWidget *parent = Q_NULLPTR);

    void setImage(const QImage& newImage);

private:
    ImageContainer *imageContainer;
    QGridLayout *layout;
    QScrollArea *scrollArea;
};


#endif //IMAGEEDITOR_IMAGEVIEWER_H
