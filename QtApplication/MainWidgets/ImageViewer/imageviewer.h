#ifndef IMAGEEDITOR_IMAGEVIEWER_H
#define IMAGEEDITOR_IMAGEVIEWER_H

#include "canvas.h"

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>

class ImageViewer : public QWidget {
public:
    explicit ImageViewer(QWidget *parent = Q_NULLPTR);

    void setImage(const QImage& newImage);

private:
    Canvas *canvas;
    QGridLayout *layout;
    QScrollArea *scrollArea;
};


#endif //IMAGEEDITOR_IMAGEVIEWER_H
