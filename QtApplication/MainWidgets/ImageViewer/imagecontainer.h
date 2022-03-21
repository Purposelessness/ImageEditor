#ifndef IMAGEEDITOR_IMAGECONTAINER_H
#define IMAGEEDITOR_IMAGECONTAINER_H

#include "icanvas.h"

#include <QWidget>
#include <QLabel>

class ImageContainer : public QLabel, public ICanvas {
public:
    explicit ImageContainer(QWidget *parent = Q_NULLPTR);

    void setImage(const QImage& newImage);

private:
    QImage image;
};


#endif //IMAGEEDITOR_IMAGECONTAINER_H
