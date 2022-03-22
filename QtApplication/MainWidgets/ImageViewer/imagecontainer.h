#ifndef IMAGEEDITOR_IMAGECONTAINER_H
#define IMAGEEDITOR_IMAGECONTAINER_H

#include "icanvas.h"

#include <QWidget>
#include <QLabel>
#include <QResizeEvent>

class ImageContainer : public QLabel, public ICanvas {
Q_OBJECT

public:
    explicit ImageContainer(QWidget *parent = Q_NULLPTR);

    void setImage(const QImage& newImage);
    void scale(float scaleValue) override;
    void adjustSize(const QSize& parentSize) override;

private:
    QPixmap originalPixmap;
    QPixmap pixmap;
};


#endif //IMAGEEDITOR_IMAGECONTAINER_H
